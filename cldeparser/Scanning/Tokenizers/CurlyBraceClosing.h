//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_CURLYBRACECLOSING_H
#define CLDEPARSER_SCANNING_TOKENIZERS_CURLYBRACECLOSING_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            class CurlyBraceClosing : public Tokenizer {

            public:
                CurlyBraceClosing() = default;
                CurlyBraceClosing(const CurlyBraceClosing &) = default;
                CurlyBraceClosing(CurlyBraceClosing &&) = default;
                CurlyBraceClosing &operator=(const CurlyBraceClosing &) = default;
                CurlyBraceClosing &operator=(CurlyBraceClosing &&) = default;
                ~CurlyBraceClosing() = default;

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


#endif //CLDEPARSER_SCANNING_TOKENIZERS_CURLYBRACECLOSING_H
