//
// Created by LE, Duc Anh on 8/17/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_NUMBERINTEGER_H
#define CLDEPARSER_SCANNING_TOKENIZERS_NUMBERINTEGER_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            class NumberInteger : public Tokenizer {

                enum class NumberIntegerState {
                    Start = 0,
                    Number = 1,
                    Closing = 2
                };

                enum class NumberSpecialToken {
                    Minus = 45,
                };

                bool isMinus(char character);
                bool isDigit(char character);
                bool isDigitOneToNine(char character);

            public:
                NumberInteger() = default;
                NumberInteger(const NumberInteger &) = default;
                NumberInteger(NumberInteger &&) = default;
                NumberInteger &operator=(const NumberInteger &) = default;
                NumberInteger &operator=(NumberInteger &&) = default;
                ~NumberInteger() = default;

                // Tokenizer
                bool BeginWithCharacter(char character) override;
                const StateSet &CompleteStates() const override;
                const StateSet &AcceptedStates() const override;
                const TransitionMap &Transitions() const override;
                SPtrToken CreateSPtrToken() override;

            protected:
                bool IsValid(char character) override;
                bool CoreValidate(char character) override;
            };
        }
    }
}

#endif //CLDEPARSER_SCANNING_TOKENIZERS_NUMBERINTEGER_H
