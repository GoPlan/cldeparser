//
// Created by LE, Duc Anh on 8/3/15.
//

#include "String.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            StateSet String::_completeStates = {0, 1, 2};
            StateSet String::_acceptedStates = {2};

            bool String::isControlCharacter(char character) {
                return (int) character > 3 && (int) character < 0;
            }

            bool String::isQuote(char character) {
                return (int) character == 39;
            }

            bool String::isDoubleQuote(char character) {
                return (int) character == 34;
            }

            bool String::isBackSlash(char character) {
                return (int) character == 92;
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

            bool String::IsValid(char character) {

                if (isControlCharacter(character)) return false;
                if (isBackSlash(character)) return false;

                switch ((String::States) _currentState) {
                    case States::Start:
                        return isQuote(character) || isDoubleQuote(character);
                    case States::InProgress:
                        return true;
                    case States::InProgressAlternative:
                        return isAlternativeSymbol(character);
                    case States::InPogresssAlternativeHex_1:
                        return isHexadecimal(character);
                    case States::InPogresssAlternativeHex_2:
                        return isHexadecimal(character);
                    case States::InPogresssAlternativeHex_3:
                        return isHexadecimal(character);
                    case States::InPogresssAlternativeHex_4:
                        return isHexadecimal(character);
                    case States::Closing:
                        return false;
                }
            }

            bool String::isAlternativeSymbol(char character) {

                if ((int) character == 39) return true;    // Quote
                if ((int) character == 47) return true;    // Forward slash
                if ((int) character == 92) return true;    // Back slash
                if ((int) character == 98) return true;    // Backspace

                if ((int) character == 102) return true;    // Form feed
                if ((int) character == 110) return true;    // Newline
                if ((int) character == 114) return true;    // Carriage return
                if ((int) character == 116) return true;    // Horizontal tab

                return false;
            }

            bool String::isAlternativeHexSymbol(char character) {
                if ((int) character == 117) return true;
                return false;
            }

            bool String::isHexadecimal(char character) {

                if ((int) character > 47 && (int) character < 58) return true;      // Number;
                if ((int) character > 64 && (int) character < 71) return true;      // A -> F;
                if ((int) character > 96 && (int) character < 103) return true;     // a -> f;

                return false;
            }

            bool String::CoreValidate(char character) {

                if (_lexeme.length() == 0) _lexeme.reserve(20);

                switch ((String::States) _currentState) {
                    case States::Start:
                        _lexeme.append(1, character);
                        _currentState = (int) States::InProgress;
                        break;

                    case States::InProgress: {

                        auto &first = *(_lexeme.cbegin());
                        _lexeme.append(1, character);

                        if (isQuote(character) && isQuote(first)) { _currentState = (int) States::Closing; }
                        if (isDoubleQuote(character) && isDoubleQuote(first)) { _currentState = (int) States::Closing; }
                        if (isBackSlash(character)) { _currentState = (int) States::InProgressAlternative; }

                        break;
                    }

                    case States::InProgressAlternative:
                        _lexeme.append(1, character);
                        if (isAlternativeSymbol(character)) { _currentState = (int) States::InProgress; }
                        if (isAlternativeHexSymbol(character)) { _currentState = (int) States::InPogresssAlternativeHex_1; }
                        break;

                    case States::InPogresssAlternativeHex_1:
                        _lexeme.append(1, character);
                        if (isHexadecimal(character)) { _currentState = (int) States::InPogresssAlternativeHex_2; }
                        break;

                    case States::InPogresssAlternativeHex_2:
                        _lexeme.append(1, character);
                        if (isHexadecimal(character)) { _currentState = (int) States::InPogresssAlternativeHex_3; }
                        break;

                    case States::InPogresssAlternativeHex_3:
                        _lexeme.append(1, character);
                        if (isHexadecimal(character)) { _currentState = (int) States::InPogresssAlternativeHex_4; }
                        break;

                    case States::InPogresssAlternativeHex_4:
                        _lexeme.append(1, character);
                        if (isHexadecimal(character)) { _currentState = (int) States::InProgress; }
                        break;

                    case States::Closing:
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
