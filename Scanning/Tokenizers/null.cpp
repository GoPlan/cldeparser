//
// Created by LE, Duc Anh on 8/12/15.
//

#include "Null.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool Null::BeginWithCharacter(char character) {
                return character == 'n';
            }

            SPtrToken Null::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::Null, _lexeme);
            }

            const StateSet &Null::CompleteStates() const {
                throw Exceptions::ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &Null::AcceptedStates() const {
                throw Exceptions::ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &Null::Transitions() const {
                throw Exceptions::ScannerException{"TransitionMap is not supported"};
            }

            bool Null::IsValid(char character) {

                switch (_currentState) {

                    case 0: {
                        return character == 'n';
                    }

                    case 1: {
                        return character == 'u';
                    }

                    case 2: {
                        return character == 'l';
                    }

                    case 3: {
                        return character == 'l';
                    }

                    default:
                        return false;
                }
            }

            bool Null::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


