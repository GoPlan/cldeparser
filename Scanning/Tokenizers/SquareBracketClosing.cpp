//
// Created by LE, Duc Anh on 8/10/15.
//

#include "SquareBracketClosing.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool SquareBracketClosing::BeginWithCharacter(char character) {
                return (int) character == 93;
            }

            SPtrToken SquareBracketClosing::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::SquareBracketClosing, _lexeme);
            }

            const StateSet &SquareBracketClosing::CompleteStates() const {
                throw Exceptions::ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &SquareBracketClosing::AcceptedStates() const {
                throw Exceptions::ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &SquareBracketClosing::Transitions() const {
                throw Exceptions::ScannerException{"TransitionMap is not supported"};
            }

            bool SquareBracketClosing::IsValid(char character) {
                return _currentState == 0 ? (int) character == 93 : false;
            }

            bool SquareBracketClosing::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}



