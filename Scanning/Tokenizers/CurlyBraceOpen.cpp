//
// Created by LE, Duc Anh on 8/4/15.
//

#include "CurlyBraceOpen.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool CurlyBraceOpen::BeginWithCharacter(char character) {
                return (int) character == 123;
            }

            SPtrToken CurlyBraceOpen::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::CurlyBraceOpen, _lexeme);
            }

            const StateSet &CurlyBraceOpen::CompleteStates() const {
                throw Exceptions::ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &CurlyBraceOpen::AcceptedStates() const {
                throw Exceptions::ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &CurlyBraceOpen::Transitions() const {
                throw Exceptions::ScannerException{"TransitionMap is not supported"};
            }

            bool CurlyBraceOpen::IsValid(char character) {
                return _currentState == 0 ? (int) character == 123 : false;
            }

            bool CurlyBraceOpen::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}



