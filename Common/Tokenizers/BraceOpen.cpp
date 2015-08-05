//
// Created by LE, Duc Anh on 8/4/15.
//

#include "BraceOpen.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            bool BraceOpen::BeginWithCharacter(char character) {
                return (int) character == 123;
            }

            SPtrToken BraceOpen::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::BraceOpen, _lexeme);
            }

            const StateSet &BraceOpen::CompleteStates() const {
                throw Exceptions::ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &BraceOpen::AcceptedStates() const {
                throw Exceptions::ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &BraceOpen::Transitions() const {
                throw Exceptions::ScannerException{"TransitionMap is not supported"};
            }

            bool BraceOpen::IsValid(char character) {
                return _currentState == 0 ? (int) character == 123 : false;
            }

            bool BraceOpen::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}



