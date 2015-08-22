//
// Created by LE, Duc Anh on 8/10/15.
//

#include "ForwardSlash.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool ForwardSlash::BeginWithCharacter(char character) {
                return (int) character == 47;
            }

            SPtrToken ForwardSlash::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::ForwardSlash, _lexeme);
            }

            const StateSet &ForwardSlash::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &ForwardSlash::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &ForwardSlash::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
            }

            bool ForwardSlash::IsValid(char character) {
                return _currentState == 0 ? (int) character == 47 : false;
            }

            bool ForwardSlash::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


