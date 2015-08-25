//
// Created by LE, Duc Anh on 8/25/15.
//

#include "CarriageReturn.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            bool CarriageReturn::BeginWithCharacter(char character) {
                return (int) character == 13;
            }

            SPtrToken CarriageReturn::CreateSPtrToken() {
                return CLDEParser::CreateSPtrToken((int) TokenType::CarriageReturn, _lexeme);
            }

            const StateSet &CarriageReturn::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &CarriageReturn::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &CarriageReturn::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
            }

            bool CarriageReturn::IsValid(char character) {
                return _currentState == 0 ? (int) character == 13 : false;
            }

            bool CarriageReturn::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}
