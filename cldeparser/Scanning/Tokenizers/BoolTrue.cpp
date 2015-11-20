//
// Created by LE, Duc Anh on 8/12/15.
//

#include "BoolTrue.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            bool BoolTrue::BeginWithCharacter(char character) {
                return character == 't';
            }

            SPtrToken BoolTrue::CreateSPtrToken() {
                return CLDEParser::CreateSPtrToken((int) TokenType::BoolTrue, _lexeme);
            }

            const StateSet &BoolTrue::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &BoolTrue::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &BoolTrue::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
            }

            bool BoolTrue::IsValid(char character) {

                switch (_currentState) {

                    case 0: {
                        return character == 't';
                    }

                    case 1: {
                        return character == 'r';
                    }

                    case 2: {
                        return character == 'u';
                    }

                    case 3: {
                        return character == 'e';
                    }

                    default:
                        return false;
                }
            }

            bool BoolTrue::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}


