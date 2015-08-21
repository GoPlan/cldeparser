//
// Created by LE, Duc Anh on 8/10/15.
//

#include "AngleBracketClosing.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool AngleBracketClosing::BeginWithCharacter(char character) {
                return (int) character == 62;
            }

            SPtrToken AngleBracketClosing::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::AngleBracketClosing, _lexeme);
            }

            const StateSet &AngleBracketClosing::CompleteStates() const {
                throw Exceptions::ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &AngleBracketClosing::AcceptedStates() const {
                throw Exceptions::ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &AngleBracketClosing::Transitions() const {
                throw Exceptions::ScannerException{"TransitionMap is not supported"};
            }

            bool AngleBracketClosing::IsValid(char character) {
                return _currentState == 0 ? (int) character == 62 : false;
            }

            bool AngleBracketClosing::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}



