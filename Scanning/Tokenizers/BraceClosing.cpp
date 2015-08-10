//
// Created by LE, Duc Anh on 8/4/15.
//

#include "BraceClosing.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool BraceClosing::BeginWithCharacter(char character) {
                return (int) character == 125;
            }

            SPtrToken BraceClosing::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::BraceClosing, _lexeme);
            }

            const StateSet &BraceClosing::CompleteStates() const {
                throw Exceptions::ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &BraceClosing::AcceptedStates() const {
                throw Exceptions::ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &BraceClosing::Transitions() const {
                throw Exceptions::ScannerException{"TransitionMap is not supported"};
            }

            bool BraceClosing::IsValid(char character) {
                return _currentState == 0 ? (int) character == 125 : false;
            }

            bool BraceClosing::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


