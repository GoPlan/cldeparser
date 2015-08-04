//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_COMMON_TOKENIZERS_ID_H
#define CLDEPARSER_COMMON_TOKENIZERS_ID_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exception/ScannerException.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            class Id : public Tokenizer {

                bool isCharacter(char character);
                bool isDigit(char character);
                bool isUnderscore(char character);

            public:
                Id() = default;
                Id(const Id &) = default;
                Id(Id &&) = default;
                Id &operator=(const Id &) = default;
                Id &operator=(Id &&) = default;
                ~Id() = default;

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


#endif //CLDEPARSER_COMMON_TOKENIZERS_ID_H
