//
// Created by LE, Duc Anh on 8/11/15.
//

#include "Subtracting.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool Subtracting::BeginWithCharacter(char character) {
                return (int) character == 45;
            }

            SPtrToken Subtracting::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::Subtracting, _lexeme);
            }

            const StateSet &Subtracting::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &Subtracting::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &Subtracting::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
            }

            bool Subtracting::IsValid(char character) {
                return _currentState == 0 ? (int) character == 45 : false;
            }

            bool Subtracting::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


