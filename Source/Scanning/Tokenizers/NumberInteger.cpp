//
// Created by LE, Duc Anh on 8/17/15.
//

#include "NumberInteger.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            bool NumberInteger::isMinus(char character) {
                return (int) character == (int) NumberInteger::NumberSpecialToken::Minus;
            }

            bool NumberInteger::isDigit(char character) {
                return (int) character > 47 && (int) character < 58;
            }

            bool NumberInteger::isDigitOneToNine(char character) {
                return isDigit(character) && (int) character != 48;
            }

            bool NumberInteger::BeginWithCharacter(char character) {
                return isMinus(character) || isDigitOneToNine(character);
            }

            const StateSet &NumberInteger::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &NumberInteger::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &NumberInteger::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
            }

            SPtrToken NumberInteger::CreateSPtrToken() {
                return CLDEParser::CreateSPtrToken((int) TokenType::NumberInteger, _lexeme);
            }

            bool NumberInteger::IsValid(char character) {

                switch ((NumberIntegerState) _currentState) {
                    case NumberIntegerState::Start:
                        return isMinus(character) || isDigitOneToNine(character);
                    case NumberIntegerState::Number:
                        return isDigitOneToNine(character);
                    case NumberIntegerState::Closing:
                        return false;
                }
            }

            bool NumberInteger::CoreValidate(char character) {

                switch ((NumberIntegerState) _currentState) {
                    case NumberIntegerState::Start:
                        _lexeme.append(1, character);
                        _currentState = (int) NumberIntegerState::Number;
                        break;
                    case NumberIntegerState::Number:
                        _lexeme.append(1, character);
                        break;
                    case NumberIntegerState::Closing:
                        return false;
                }

                return true;
            }
        }
    }
}


