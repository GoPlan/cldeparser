//
// Created by LE, Duc Anh on 8/5/15.
//

#ifndef CLDEPARSER_COMMON_TOKENIZERS_PARENTHESESOPEN_H
#define CLDEPARSER_COMMON_TOKENIZERS_PARENTHESESOPEN_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exception/ScannerException.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            class ParenthesesOpen : public Tokenizer {

            public:
                ParenthesesOpen() = default;
                ParenthesesOpen(const ParenthesesOpen &) = default;
                ParenthesesOpen(ParenthesesOpen &&) = default;
                ParenthesesOpen &operator=(const ParenthesesOpen &) = default;
                ParenthesesOpen &operator=(ParenthesesOpen &&) = default;
                ~ParenthesesOpen() = default;

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


#endif //CLDEPARSER_PARENTHESESOPEN_H
