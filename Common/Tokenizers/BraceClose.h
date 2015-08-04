//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_COMMON_TOKENIZERS_BRACECLOSE_H
#define CLDEPARSER_COMMON_TOKENIZERS_BRACECLOSE_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exception/ScannerException.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            class BraceClose : public Tokenizer {

            public:
                BraceClose() = default;
                BraceClose(const BraceClose &) = default;
                BraceClose(BraceClose &&) = default;
                BraceClose &operator=(const BraceClose &) = default;
                BraceClose &operator=(BraceClose &&) = default;
                ~BraceClose() = default;

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


#endif //CLDEPARSER_COMMON_TOKENIZERS_BRACECLOSE_H
