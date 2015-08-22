//
// Created by LE, Duc Anh on 8/5/15.
//

#include "ParenthesesClosing.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool ParenthesesClosing::BeginWithCharacter(char character) {
                return (int) character == 40;
            }

            SPtrToken ParenthesesClosing::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::ParenthesesClosing, _lexeme);
            }

            const StateSet &ParenthesesClosing::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &ParenthesesClosing::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &ParenthesesClosing::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
            }

            bool ParenthesesClosing::IsValid(char character) {
                return _currentState == 0 ? (int) character == 40 : false;
            }

            bool ParenthesesClosing::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


