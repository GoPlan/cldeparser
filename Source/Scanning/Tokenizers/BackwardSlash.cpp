//
// Created by LE, Duc Anh on 8/10/15.
//

#include "BackwardSlash.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            bool BackwardSlash::BeginWithCharacter(char character) {
                return (int) character == 92;
            }

            SPtrToken BackwardSlash::CreateSPtrToken() {
                return CLDEParser::CreateSPtrToken((int) TokenType::BackwardSlash, _lexeme);
            }

            const StateSet &BackwardSlash::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &BackwardSlash::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &BackwardSlash::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
            }

            bool BackwardSlash::IsValid(char character) {
                return _currentState == 0 ? (int) character == 92 : false;
            }

            bool BackwardSlash::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


