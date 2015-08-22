//
// Created by LE, Duc Anh on 8/4/15.
//

#include "Colon.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool Colon::BeginWithCharacter(char character) {
                return (int) character == 58;
            }

            const StateSet &Colon::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &Colon::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &Colon::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
            }

            SPtrToken Colon::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::Colon, _lexeme);
            }

            bool Colon::IsValid(char character) {
                return _currentState == 0 ? (int) character == 58 : false;
            }

            bool Colon::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


