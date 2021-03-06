//
// Created by LE, Duc Anh on 8/11/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_DIVISION_H
#define CLDEPARSER_SCANNING_TOKENIZERS_DIVISION_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            class Division : public Tokenizer {

            public:
                Division() = default;
                Division(const Division &) = default;
                Division(Division &&) = default;
                Division &operator=(const Division &) = default;
                Division &operator=(Division &&) = default;
                ~Division() = default;

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


#endif //CLDEPARSER_SCANNING_TOKENIZERS_DIVISION_H
