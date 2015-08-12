//
// Created by LE, Duc Anh on 8/4/15.
//

#include "CurlyBraceClosing.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool CurlyBraceClosing::BeginWithCharacter(char character) {
                return (int) character == 125;
            }

            SPtrToken CurlyBraceClosing::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::CurlyBraceClosing, _lexeme);
            }

            const StateSet &CurlyBraceClosing::CompleteStates() const {
                throw Exceptions::ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &CurlyBraceClosing::AcceptedStates() const {
                throw Exceptions::ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &CurlyBraceClosing::Transitions() const {
                throw Exceptions::ScannerException{"TransitionMap is not supported"};
            }

            bool CurlyBraceClosing::IsValid(char character) {
                return _currentState == 0 ? (int) character == 125 : false;
            }

            bool CurlyBraceClosing::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


