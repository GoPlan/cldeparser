//
// Created by LE, Duc Anh on 8/10/15.
//

#include "SquareBracketOpen.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool SquareBracketOpen::BeginWithCharacter(char character) {
                return (int) character == 91;
            }

            SPtrToken SquareBracketOpen::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::SquareBracketOpen, _lexeme);
            }

            const StateSet &SquareBracketOpen::CompleteStates() const {
                throw Exceptions::ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &SquareBracketOpen::AcceptedStates() const {
                throw Exceptions::ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &SquareBracketOpen::Transitions() const {
                throw Exceptions::ScannerException{"TransitionMap is not supported"};
            }

            bool SquareBracketOpen::IsValid(char character) {
                return _currentState == 0 ? (int) character == 91 : false;
            }

            bool SquareBracketOpen::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


