//
// Created by LE, Duc Anh on 8/4/15.
//

#include "Space.h"
#include "../../Exceptions/ScannerException.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            bool Space::BeginWithCharacter(char character) {
                return (int) character == 32;
            }

            SPtrToken Space::CreateSPtrToken() {
                return CLDEParser::CreateSPtrToken((int) TokenType::Space, _lexeme);
            }

            const StateSet &Space::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &Space::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &Space::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
            }

            bool Space::IsValid(char character) {
                return _currentState == 0 ? (int) character == 32 : false;
            }

            bool Space::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


