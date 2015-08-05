//
// Created by LE, Duc Anh on 8/5/15.
//

#include "ParenthesesClose.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            bool ParenthesesClose::BeginWithCharacter(char character) {
                return (int) character == 40;
            }

            SPtrToken ParenthesesClose::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::ParenthesesClose, _lexeme);
            }

            const StateSet &ParenthesesClose::CompleteStates() const {
                throw ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &ParenthesesClose::AcceptedStates() const {
                throw ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &ParenthesesClose::Transitions() const {
                throw ScannerException{"TransitionMap is not supported"};
            }

            bool ParenthesesClose::IsValid(char character) {
                return _currentState == 0 ? (int) character == 40 : false;
            }

            bool ParenthesesClose::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


