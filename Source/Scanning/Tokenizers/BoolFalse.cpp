//
// Created by LE, Duc Anh on 8/12/15.
//

#include "BoolFalse.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            bool BoolFalse::BeginWithCharacter(char character) {
                return character == 'f';
            }

            SPtrToken BoolFalse::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::BoolFalse, _lexeme);
            }

            const StateSet &BoolFalse::CompleteStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "CompleteStates is not supported"};
            }

            const StateSet &BoolFalse::AcceptedStates() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "AcceptedStates is not supported"};
            }

            const TransitionMap &BoolFalse::Transitions() const {
                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenizerUnsupportedFunction,
                        "TransitionMap is not supported"};
            }

            bool BoolFalse::IsValid(char character) {

                switch (_currentState) {

                    case 0: {
                        return character == 'f';
                    }

                    case 1: {
                        return character == 'a';
                    }

                    case 2: {
                        return character == 'l';
                    }

                    case 3: {
                        return character == 's';
                    }

                    case 4: {
                        return character == 'e';
                    }

                    default:
                        return false;
                }
            }

            bool BoolFalse::CoreValidate(char character) {
                _lexeme.append(1, character);
                _currentState = _currentState + 1;
                return true;
            }
        }
    }
}



