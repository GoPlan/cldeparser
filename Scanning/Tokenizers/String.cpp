//
// Created by LE, Duc Anh on 8/3/15.
//

#include "String.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool String::isControlCharacter(char character) {
                return (int) character > 3 && (int) character < 0;
            }

            bool String::isQuote(char character) {
                return (int) character == (int) StringSpecialToken::SingleQuote;
            }

            bool String::isDoubleQuote(char character) {
                return (int) character == (int) StringSpecialToken::DoubleQuote;
            }

            bool String::isBackSlash(char character) {
                return (int) character == (int) StringSpecialToken::BackSlash;
            }

            bool String::BeginWithCharacter(char character) {
                return isQuote(character) || isDoubleQuote(character);
            }

            const StateSet &String::CompleteStates() const {
                throw Exceptions::ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &String::AcceptedStates() const {
                throw Exceptions::ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &String::Transitions() const {
                throw Exceptions::ScannerException{"TransitionMap is not supported"};
            }

            bool String::isAlternativeSymbol(char character) {

                bool result = false;

                if ((int) character == (int) StringSpecialToken::DoubleQuote) result = true;    // Quote
                if ((int) character == (int) StringSpecialToken::ForwardSlash) result = true;    // Forward slash
                if ((int) character == (int) StringSpecialToken::BackSlash) result = true;    // Back slash
                if ((int) character == 98) result = true;    // b - Backspace

                if ((int) character == 102) result = true;    // f - Form feed
                if ((int) character == 110) result = true;    // n - Newline
                if ((int) character == 114) result = true;    // r - Carriage return
                if ((int) character == 116) result = true;    // t - Horizontal tab
                if ((int) character == 117) result = true;    // u - Horizontal tab

                return result;
            }

            bool String::isAlternativeHexSymbol(char character) {
                return (int) character == 117;
            }

            bool String::isHexadecimal(char character) {

                bool result = false;

                if ((int) character > 47 && (int) character < 58) result = true;      // Number;
                if ((int) character > 64 && (int) character < 71) result = true;      // A -> F;
                if ((int) character > 96 && (int) character < 103) result = true;     // a -> f;

                return result;
            }

            bool String::IsValid(char character) {

                if (isControlCharacter(character)) return false;

                switch ((String::StringState) _currentState) {
                    case StringState::Start:
                        return isQuote(character) || isDoubleQuote(character);
                    case StringState::InProgress:
                        return true;
                    case StringState::InProgressAlternative:
                        return isAlternativeSymbol(character);
                    case StringState::InPogresssAlternativeHex_1:
                        return isHexadecimal(character);
                    case StringState::InPogresssAlternativeHex_2:
                        return isHexadecimal(character);
                    case StringState::InPogresssAlternativeHex_3:
                        return isHexadecimal(character);
                    case StringState::InPogresssAlternativeHex_4:
                        return isHexadecimal(character);
                    case StringState::Closing:
                        return false;
                }
            }

            bool String::CoreValidate(char character) {

                if (_lexeme.length() == 0) _lexeme.reserve(20);

                switch ((String::StringState) _currentState) {
                    case StringState::Start:
                        _wrapChar = character;
                        _currentState = (int) StringState::InProgress;
                        break;

                    case StringState::InProgress: {

                        if ((isQuote(character) && isQuote(_wrapChar))
                            || (isDoubleQuote(character) && isDoubleQuote(_wrapChar))) {
                            _currentState = (int) StringState::Closing;
                            break;
                        }

                        if (isBackSlash(character)) {
                            _currentState = (int) StringState::InProgressAlternative;
                        }

                        _lexeme.append(1, character);

                        break;
                    }

                    case StringState::InProgressAlternative:
                        _lexeme.append(1, character);
                        if (isAlternativeSymbol(character)) { _currentState = (int) StringState::InProgress; }
                        if (isAlternativeHexSymbol(character)) { _currentState = (int) StringState::InPogresssAlternativeHex_1; }
                        break;

                    case StringState::InPogresssAlternativeHex_1:
                        _lexeme.append(1, character);
                        if (isHexadecimal(character)) { _currentState = (int) StringState::InPogresssAlternativeHex_2; }
                        break;

                    case StringState::InPogresssAlternativeHex_2:
                        _lexeme.append(1, character);
                        if (isHexadecimal(character)) { _currentState = (int) StringState::InPogresssAlternativeHex_3; }
                        break;

                    case StringState::InPogresssAlternativeHex_3:
                        _lexeme.append(1, character);
                        if (isHexadecimal(character)) { _currentState = (int) StringState::InPogresssAlternativeHex_4; }
                        break;

                    case StringState::InPogresssAlternativeHex_4:
                        _lexeme.append(1, character);
                        if (isHexadecimal(character)) { _currentState = (int) StringState::InProgress; }
                        break;

                    case StringState::Closing:
                        return false;
                }

                return true;
            }

            SPtrToken String::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::String, _lexeme);
            }
        }
    }
}
