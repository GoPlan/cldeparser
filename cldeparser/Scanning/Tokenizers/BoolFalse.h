//
// Created by LE, Duc Anh on 8/12/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_BOOLFALSE_H
#define CLDEPARSER_SCANNING_TOKENIZERS_BOOLFALSE_H

#include "../../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            class BoolFalse : public Tokenizer {

            public:
                BoolFalse() = default;
                BoolFalse(const BoolFalse &) = default;
                BoolFalse(BoolFalse &&) = default;
                BoolFalse &operator=(const BoolFalse &) = default;
                BoolFalse &operator=(BoolFalse &&) = default;
                ~BoolFalse() = default;

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


#endif //CLDEPARSER_SCANNING_TOKENIZERS_BOOLFALSE_H
