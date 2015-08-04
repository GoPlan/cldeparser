//
// Created by LE, Duc Anh on 8/3/15.
//

#include "Number.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            bool Number::isPlus(char character) {
                return (int) character == (int) Number::NumberSpecialToken::Plus;
            }

            bool Number::isMinus(char character) {
                return (int) character == (int) Number::NumberSpecialToken::Minus;
            }

            bool Number::isDot(char character) {
                return (int) character == (int) Number::NumberSpecialToken::Dot;
            }

            bool Number::isDigit(char character) {
                return (int) character > 47 && (int) character < 58;
            }

            bool Number::isDigitOneToNine(char character) {
                return isDigit(character) && (int) character != 48;
            }

            bool Number::isZero(char character) {
                return (int) character == (int) Number::NumberSpecialToken::Zero;
            }

            bool Number::BeginWithCharacter(char character) {
                return isMinus(character) || isDigit(character) || isDot(character);
            }

            SPtrToken Number::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::Number, _lexeme);
            }

            const StateSet &Number::CompleteStates() const {
                throw ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &Number::AcceptedStates() const {
                throw ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &Number::Transitions() const {
                throw ScannerException{"TransitionMap is not supported"};
            }

            bool Number::IsValid(char character) {
                return isDigit(character);
            }

            bool Number::CoreValidate(char character) {
                return Tokenizer::CoreValidate(character);
            }
        }
    }
}


