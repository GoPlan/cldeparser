//
// Created by LE, Duc Anh on 8/4/15.
//

#include "BracketClose.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool BracketClose::BeginWithCharacter(char character) {
                return (int) character == 93;
            }

            SPtrToken BracketClose::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::BracketClose, _lexeme);
            }

            const StateSet &BracketClose::CompleteStates() const {
                throw Exceptions::ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &BracketClose::AcceptedStates() const {
                throw Exceptions::ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &BracketClose::Transitions() const {
                throw Exceptions::ScannerException{"TransitionMap is not supported"};
            }

            bool BracketClose::IsValid(char character) {
                return _currentState == 0 ? (int) character == 93 : false;
            }

            bool BracketClose::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}

