//
// Created by LE, Duc Anh on 8/5/15.
//

#include "ParenthesesOpen.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            bool ParenthesesOpen::BeginWithCharacter(char character) {
                return (int) character == 41;
            }

            SPtrToken ParenthesesOpen::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::ParenthesesOpen, _lexeme);
            }

            const StateSet &ParenthesesOpen::CompleteStates() const {
                throw ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &ParenthesesOpen::AcceptedStates() const {
                throw ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &ParenthesesOpen::Transitions() const {
                throw ScannerException{"TransitionMap is not supported"};
            }

            bool ParenthesesOpen::IsValid(char character) {
                return _currentState == 0 ? (int) character == 41 : false;
            }

            bool ParenthesesOpen::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


