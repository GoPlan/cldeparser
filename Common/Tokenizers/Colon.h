//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_COMMON_TOKENIZERS_COLON_H
#define CLDEPARSER_COMMON_TOKENIZERS_COLON_H

#include "../../Tokenizer.h"
#include "../TokenType.h"
#include "../../Exceptions/ScannerException.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            class Colon : public Tokenizer {

            public:
                Colon() = default;
                Colon(const Colon &) = default;
                Colon(Colon &&) = default;
                Colon &operator=(const Colon &) = default;
                Colon &operator=(Colon &&) = default;
                ~Colon() = default;

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


#endif //CLDEPARSER_COMMON_TOKENIZERS_COLON_H
