//
// Created by LE, Duc Anh on 8/11/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_ADDING_H
#define CLDEPARSER_SCANNING_TOKENIZERS_ADDING_H

#include "../../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            class Adding : public Tokenizer {

            public:
                Adding() = default;
                Adding(const Adding &) = default;
                Adding(Adding &&) = default;
                Adding &operator=(const Adding &) = default;
                Adding &operator=(Adding &&) = default;
                ~Adding() = default;

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


#endif //CLDEPARSER_SCANNING_TOKENIZERS_ADDING_H
