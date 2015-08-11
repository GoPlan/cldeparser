//
// Created by LE, Duc Anh on 8/11/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_MULTIPLICATION_H
#define CLDEPARSER_SCANNING_TOKENIZERS_MULTIPLICATION_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            class Multiplication : public Tokenizer {

            public:
                Multiplication() = default;
                Multiplication(const Multiplication &) = default;
                Multiplication(Multiplication &&) = default;
                Multiplication &operator=(const Multiplication &) = default;
                Multiplication &operator=(Multiplication &&) = default;
                ~Multiplication() = default;

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


#endif //CLDEPARSER_SCANNING_TOKENIZERS_MULTIPLICATION_H
