//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_COMMON_TOKENIZERS_ID_H
#define CLDEPARSER_COMMON_TOKENIZERS_ID_H

#include "../../Tokenizer.h"
#include "../TokenType.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            class Id : public Tokenizer {

                bool isCharacter(char character);
                bool isNumber(char character);

            public:
                Id() = default;
                Id(const Id &) = default;
                Id(Id &&) = default;
                Id &operator=(const Id &) = default;
                Id &operator=(Id &&) = default;
                ~Id() = default;

                // Tokenizer
                bool IsValid(char character) override;
                SPtrToken CreateSPtrToken() override;
            };
        }
    }
}


#endif //CLDEPARSER_COMMON_TOKENIZERS_ID_H
