//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_COMMON_TOKENIZERS_BRACKETCLOSE_H
#define CLDEPARSER_COMMON_TOKENIZERS_BRACKETCLOSE_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            class BracketClose : public Tokenizer {

            public:
                BracketClose() = default;
                BracketClose(const BracketClose &) = default;
                BracketClose(BracketClose &&) = default;
                BracketClose &operator=(const BracketClose &) = default;
                BracketClose &operator=(BracketClose &&) = default;
                ~BracketClose() = default;

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


#endif //CLDEPARSER_COMMON_TOKENIZERS_BRACKETCLOSE_H
