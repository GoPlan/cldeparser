//
// Created by LE, Duc Anh on 8/11/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_SUBTRACTING_H
#define CLDEPARSER_SCANNING_TOKENIZERS_SUBTRACTING_H

#include "../../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            class Subtracting : public Tokenizer {

            public:
                Subtracting() = default;
                Subtracting(const Subtracting &) = default;
                Subtracting(Subtracting &&) = default;
                Subtracting &operator=(const Subtracting &) = default;
                Subtracting &operator=(Subtracting &&) = default;
                ~Subtracting() = default;

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


#endif //CLDEPARSER_SCANNING_TOKENIZERS_SUBTRACTING_H
