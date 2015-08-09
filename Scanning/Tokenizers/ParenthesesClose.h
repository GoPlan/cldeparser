//
// Created by LE, Duc Anh on 8/5/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_PARENTHESESCLOSE_H
#define CLDEPARSER_SCANNING_TOKENIZERS_PARENTHESESCLOSE_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            class ParenthesesClose : public Tokenizer {

            public:
                ParenthesesClose() = default;
                ParenthesesClose(const ParenthesesClose &) = default;
                ParenthesesClose(ParenthesesClose &&) = default;
                ParenthesesClose &operator=(const ParenthesesClose &) = default;
                ParenthesesClose &operator=(ParenthesesClose &&) = default;
                ~ParenthesesClose() = default;

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


#endif //CLDEPARSER_SCANNING_TOKENIZERS_PARENTHESESCLOSE_H
