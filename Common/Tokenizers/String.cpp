//
// Created by LE, Duc Anh on 8/3/15.
//

#include "String.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            StateSet String::_completeStates = {0, 1, 2};
            StateSet String::_acceptedStates = {2};

            bool String::isControlCharacter(char character) {
                return (int) character < 32;
            }

            bool String::isQuote(char character) {
                return (int) character == 39;
            }

            bool String::isBackSlash(char character) {
                return (int) character == 92;
            }

            bool String::BeginWithCharacter(char character) {
                return isQuote(character);
            }

            const StateSet &String::CompleteStates() const {
                throw ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &String::AcceptedStates() const {
                throw ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &String::Transitions() const {
                throw ScannerException{"TransitionMap is not supported"};
            }

            bool String::IsValid(char character) {
                if (isControlCharacter(character)) return false;
                return true;
            }

            bool String::CoreValidate(char character) {

                if (_lexeme.length() == 0) _lexeme.reserve(20);

                switch ((String::States) _currentState) {
                    case States::Start:
                        _lexeme.append(1, character);
                        _currentState = _currentState + 1;
                        break;
                    case States::InProgress:
                        _lexeme.append(1, character);
                        if (isQuote(character))_currentState = _currentState + 1;
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
