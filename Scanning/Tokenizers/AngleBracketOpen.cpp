//
// Created by LE, Duc Anh on 8/10/15.
//

#include "AngleBracketOpen.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool AngleBracketOpen::BeginWithCharacter(char character) {
                return (int) character == 60;
            }

            SPtrToken AngleBracketOpen::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::AngleBracketOpen, _lexeme);
            }

            const StateSet &AngleBracketOpen::CompleteStates() const {
                throw Exceptions::ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &AngleBracketOpen::AcceptedStates() const {
                throw Exceptions::ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &AngleBracketOpen::Transitions() const {
                throw Exceptions::ScannerException{"TransitionMap is not supported"};
            }

            bool AngleBracketOpen::IsValid(char character) {
                return _currentState == 0 ? (int) character == 60 : false;
            }

            bool AngleBracketOpen::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


