//
// Created by LE, Duc Anh on 8/4/15.
//

#include "SemiColon.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            bool SemiColon::BeginWithCharacter(char character) {
                return (int) character == 59;
            }

            const StateSet &SemiColon::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &SemiColon::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &SemiColon::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
            }

            SPtrToken SemiColon::CreateSPtrToken() {
                return CLDEParser::CreateSPtrToken((int) TokenType::SemiColon, _lexeme);
            }

            bool SemiColon::IsValid(char character) {
                return _currentState == 0 ? (int) character == 59 : false;
            }

            bool SemiColon::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


