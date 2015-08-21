//
// Created by LE, Duc Anh on 8/11/15.
//

#include "Division.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool Division::BeginWithCharacter(char character) {
                return (int) character == 47;
            }

            SPtrToken Division::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::Division, _lexeme);
            }

            const StateSet &Division::CompleteStates() const {
                throw Exceptions::ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &Division::AcceptedStates() const {
                throw Exceptions::ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &Division::Transitions() const {
                throw Exceptions::ScannerException{"TransitionMap is not supported"};
            }

            bool Division::IsValid(char character) {
                return _currentState == 0 ? (int) character == 47 : false;
            }

            bool Division::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


