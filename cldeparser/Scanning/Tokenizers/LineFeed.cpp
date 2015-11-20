//
// Created by LE, Duc Anh on 8/25/15.
//

#include "LineFeed.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            bool LineFeed::BeginWithCharacter(char character) {
                return (int) character == 10;
            }

            SPtrToken LineFeed::CreateSPtrToken() {
                return CLDEParser::CreateSPtrToken((int) TokenType::LineFeed, _lexeme);
            }

            const StateSet &LineFeed::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &LineFeed::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &LineFeed::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
            }

            bool LineFeed::IsValid(char character) {
                return _currentState == 0 ? (int) character == 10 : false;
            }

            bool LineFeed::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


