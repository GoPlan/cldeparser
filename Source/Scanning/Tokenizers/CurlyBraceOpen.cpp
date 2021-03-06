//
// Created by LE, Duc Anh on 8/4/15.
//

#include "CurlyBraceOpen.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            bool CurlyBraceOpen::BeginWithCharacter(char character) {
                return (int) character == 123;
            }

            SPtrToken CurlyBraceOpen::CreateSPtrToken() {
                return CLDEParser::CreateSPtrToken((int) TokenType::CurlyBraceOpen, _lexeme);
            }

            const StateSet &CurlyBraceOpen::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &CurlyBraceOpen::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &CurlyBraceOpen::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
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



