//
// Created by LE, Duc Anh on 8/11/15.
//

#include "Adding.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            bool Adding::BeginWithCharacter(char character) {
                return (int) character == 43;
            }

            SPtrToken Adding::CreateSPtrToken() {
                return CLDEParser::CreateSPtrToken((int) TokenType::Adding, _lexeme);
            }

            const StateSet &Adding::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &Adding::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &Adding::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
            }

            bool Adding::IsValid(char character) {
                return _currentState == 0 ? (int) character == 43 : false;
            }

            bool Adding::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}



