//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_BRACECLOSING_H
#define CLDEPARSER_SCANNING_TOKENIZERS_BRACECLOSING_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            class BraceClosing : public Tokenizer {

            public:
                BraceClosing() = default;
                BraceClosing(const BraceClosing &) = default;
                BraceClosing(BraceClosing &&) = default;
                BraceClosing &operator=(const BraceClosing &) = default;
                BraceClosing &operator=(BraceClosing &&) = default;
                ~BraceClosing() = default;

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


#endif //CLDEPARSER_SCANNING_TOKENIZERS_BRACECLOSING_H
