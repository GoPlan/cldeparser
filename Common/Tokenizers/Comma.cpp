//
// Created by LE, Duc Anh on 8/4/15.
//

#include "Comma.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            bool Comma::BeginWithCharacter(char character) {
                return (int) character == 44;
            }

            SPtrToken Comma::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::Comma, _lexeme);
            }

            const StateSet &Comma::CompleteStates() const {
                throw ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &Comma::AcceptedStates() const {
                throw ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &Comma::Transitions() const {
                throw ScannerException{"TransitionMap is not supported"};
            }

            bool Comma::IsValid(char character) {
                return _currentState == 0 ? (int) character == 44 : false;
            }

            bool Comma::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


