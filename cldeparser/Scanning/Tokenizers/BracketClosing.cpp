//
// Created by LE, Duc Anh on 8/4/15.
//

#include "BracketClosing.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            bool BracketClosing::BeginWithCharacter(char character) {
                return (int) character == 93;
            }

            SPtrToken BracketClosing::CreateSPtrToken() {
                return CLDEParser::CreateSPtrToken((int) TokenType::BracketClosing, _lexeme);
            }

            const StateSet &BracketClosing::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &BracketClosing::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &BracketClosing::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
            }

            bool BracketClosing::IsValid(char character) {
                return _currentState == 0 ? (int) character == 93 : false;
            }

            bool BracketClosing::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}

