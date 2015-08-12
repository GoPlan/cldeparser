//
// Created by LE, Duc Anh on 8/12/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_NULL_H
#define CLDEPARSER_SCANNING_TOKENIZERS_NULL_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            class Null : public Tokenizer {

            public:
                Null() = default;
                Null(const Null &) = default;
                Null(Null &&) = default;
                Null &operator=(const Null &) = default;
                Null &operator=(Null &&) = default;
                ~Null() = default;

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


#endif //CLDEPARSER_SCANNING_TOKENIZERS_NULL_H
