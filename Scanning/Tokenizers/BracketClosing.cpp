//
// Created by LE, Duc Anh on 8/4/15.
//

#include "BracketClosing.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool BracketClosing::BeginWithCharacter(char character) {
                return (int) character == 93;
            }

            SPtrToken BracketClosing::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::BracketClose, _lexeme);
            }

            const StateSet &BracketClosing::CompleteStates() const {
                throw Exceptions::ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &BracketClosing::AcceptedStates() const {
                throw Exceptions::ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &BracketClosing::Transitions() const {
                throw Exceptions::ScannerException{"TransitionMap is not supported"};
            }

            bool BracketClosing::IsValid(char character) {
                return _currentState == 0 ? (int) character == 93 : false;
            }

            bool BracketClosing::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}

