//
// Created by LE, Duc Anh on 8/11/15.
//

#include "Multiplication.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool Multiplication::BeginWithCharacter(char character) {
                return (int) character == 42;
            }

            SPtrToken Multiplication::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::Multiplication, _lexeme);
            }

            const StateSet &Multiplication::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &Multiplication::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &Multiplication::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
            }

            bool Multiplication::IsValid(char character) {
                return _currentState == 0 ? (int) character == 42 : false;
            }

            bool Multiplication::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


