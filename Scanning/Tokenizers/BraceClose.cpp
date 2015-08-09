//
// Created by LE, Duc Anh on 8/4/15.
//

#include "BraceClose.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool BraceClose::BeginWithCharacter(char character) {
                return (int) character == 125;
            }

            SPtrToken BraceClose::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::BraceClose, _lexeme);
            }

            const StateSet &BraceClose::CompleteStates() const {
                throw Exceptions::ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &BraceClose::AcceptedStates() const {
                throw Exceptions::ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &BraceClose::Transitions() const {
                throw Exceptions::ScannerException{"TransitionMap is not supported"};
            }

            bool BraceClose::IsValid(char character) {
                return _currentState == 0 ? (int) character == 125 : false;
            }

            bool BraceClose::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}

