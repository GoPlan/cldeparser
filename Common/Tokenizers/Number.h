//
// Created by LE, Duc Anh on 8/3/15.
//

#ifndef CLDEPARSER_COMMON_TOKENIZERS_VALUE_H
#define CLDEPARSER_COMMON_TOKENIZERS_VALUE_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exception/ScannerException.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            class Number : public Tokenizer {

                enum class NumberSpecialToken {
                    Zero = 48,
                    Plus = 43,
                    Comma = 44,
                    Minus = 45,
                    Dot = 46,
                    LowerE = 69,
                    UpperE = 101
                };

                bool isPlus(char character);
                bool isMinus(char character);
                bool isDot(char character);
                bool isDigit(char character);
                bool isDigitOneToNine(char character);
                bool isZero(char character);

            public:
                Number() = default;
                Number(const Number &) = default;
                Number(Number &&) = default;
                Number &operator=(const Number &) = default;
                Number &operator=(Number &&) = default;
                ~Number() = default;

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


#endif //CLDEPARSER_COMMON_TOKENIZERS_VALUE_H
