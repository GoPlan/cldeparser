//
// Created by LE, Duc Anh on 8/5/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_PARENTHESESCLOSING_H
#define CLDEPARSER_SCANNING_TOKENIZERS_PARENTHESESCLOSING_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            class ParenthesesClosing : public Tokenizer {

            public:
                ParenthesesClosing() = default;
                ParenthesesClosing(const ParenthesesClosing &) = default;
                ParenthesesClosing(ParenthesesClosing &&) = default;
                ParenthesesClosing &operator=(const ParenthesesClosing &) = default;
                ParenthesesClosing &operator=(ParenthesesClosing &&) = default;
                ~ParenthesesClosing() = default;

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


#endif //CLDEPARSER_SCANNING_TOKENIZERS_PARENTHESESCLOSING_H
