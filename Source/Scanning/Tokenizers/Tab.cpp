//
// Created by LE, Duc Anh on 8/4/15.
//

#include "Tab.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            bool Tab::BeginWithCharacter(char character) {
                return (int) character == 9;
            }

            SPtrToken Tab::CreateSPtrToken() {
                return CLDEParser::CreateSPtrToken((int) TokenType::Tab, _lexeme);
            }

            const StateSet &Tab::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &Tab::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &Tab::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
            }

            bool Tab::IsValid(char character) {
                return _currentState == 0 ? (int) character == 9 : false;
            }

            bool Tab::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


