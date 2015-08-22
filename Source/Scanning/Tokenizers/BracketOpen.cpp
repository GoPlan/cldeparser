//
// Created by LE, Duc Anh on 8/4/15.
//

#include "BracketOpen.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool BracketOpen::BeginWithCharacter(char character) {
                return (int) character == 91;
            }

            SPtrToken BracketOpen::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::BracketOpen, _lexeme);
            }

            const StateSet &BracketOpen::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &BracketOpen::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &BracketOpen::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
            }

            bool BracketOpen::IsValid(char character) {
                return _currentState == 0 ? (int) character == 91 : false;
            }

            bool BracketOpen::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


