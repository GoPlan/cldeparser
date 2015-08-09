//
// Created by LE, Duc Anh on 8/3/15.
//

#include "Number.h"

namespace CldeParser {
    namespace Scanning {
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

            bool Number::isExponentialSymbol(char character) {
                return (int) character == (int) Number::NumberSpecialToken::LowerE
                       || (int) character == (int) Number::NumberSpecialToken::UpperE;
            }

            bool Number::BeginWithCharacter(char character) {
                return isMinus(character) || isDigit(character) || isDot(character);
            }

            SPtrToken Number::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::Number, _lexeme);
            }

            const StateSet &Number::CompleteStates() const {
                throw Exceptions::ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &Number::AcceptedStates() const {
                throw Exceptions::ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &Number::Transitions() const {
                throw Exceptions::ScannerException{"TransitionMap is not supported"};
            }

            bool Number::IsValid(char character) {

                switch ((States) _currentState) {
                    case States::Start:
                        return isMinus(character) || isDigit(character);
                    case States::Negation:
                        return isDigit(character);
                    case States::RationalPercent:
                        return isDot(character) || isExponentialSymbol(character);
                    case States::Number:
                        return isDigit(character) || isDot(character) || isExponentialSymbol(character);
                    case States::Decimal:
                        return isDigit(character) || isExponentialSymbol(character);
                    case States::Exponential_1:
                        return isDigit(character) || isPlus(character) || isMinus(character);
                    case States::Exponential_2:
                        return isDigit(character);
                    case States::Closing:
                        return false;
                }
            }

            bool Number::CoreValidate(char character) {

                if (_lexeme.length() == 0)
                    _lexeme.reserve(20);

                switch ((States) _currentState) {

                    case States::Start: {
                        _lexeme.append(1, character);
                        if (isMinus(character)) _currentState = (int) States::Negation;
                        if (isZero(character)) _currentState = (int) States::RationalPercent;
                        if (isDigitOneToNine(character)) _currentState = (int) States::Number;
                        break;
                    }

                    case States::Negation: {
                        _lexeme.append(1, character);
                        if (isZero(character)) _currentState = (int) States::RationalPercent;
                        if (isDigitOneToNine(character)) _currentState = (int) States::Number;
                        break;
                    }

                    case States::RationalPercent: {
                        _lexeme.append(1, character);
                        if (isDot(character)) _currentState = (int) States::Decimal;
                        if (isExponentialSymbol(character)) _currentState = (int) States::Exponential_1;
                        break;
                    }

                    case States::Number: {
                        _lexeme.append(1, character);
                        if (isDigit(character)) _currentState = (int) States::Number;
                        if (isDot(character)) _currentState = (int) States::Decimal;
                        if (isExponentialSymbol(character)) _currentState = (int) States::Exponential_1;
                        break;
                    }

                    case States::Decimal: {
                        _lexeme.append(1, character);
                        if (isDigit(character)) _currentState = (int) States::Decimal;
                        if (isExponentialSymbol(character)) _currentState = (int) States::Exponential_1;
                        break;
                    }

                    case States::Exponential_1: {
                        _lexeme.append(1, character);
                        _currentState = (int) States::Exponential_2;
                        break;
                    }

                    case States::Exponential_2: {
                        _lexeme.append(1, character);
                        _currentState = (int) States::Exponential_2;
                        break;
                    }

                    case States::Closing:
                        return false;
                }

                return true;
            }
        }
    }
}


