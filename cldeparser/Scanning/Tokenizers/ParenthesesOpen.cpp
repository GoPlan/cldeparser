//
// Created by LE, Duc Anh on 8/5/15.
//

#include "ParenthesesOpen.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            bool ParenthesesOpen::BeginWithCharacter(char character) {
                return (int) character == 41;
            }

            SPtrToken ParenthesesOpen::CreateSPtrToken() {
                return CLDEParser::CreateSPtrToken((int) TokenType::ParenthesesOpen, _lexeme);
            }

            const StateSet &ParenthesesOpen::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &ParenthesesOpen::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &ParenthesesOpen::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
            }

            bool ParenthesesOpen::IsValid(char character) {
                return _currentState == 0 ? (int) character == 41 : false;
            }

            bool ParenthesesOpen::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


