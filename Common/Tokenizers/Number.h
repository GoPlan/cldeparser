//
// Created by LE, Duc Anh on 8/3/15.
//

#ifndef[CLDEPARSER_COMMON_TOKENIZERS_VALUE_H
#define CLDEPARSER_COMMON_TOKENIZERS_VALUE_H

#include "../TokenType.h"
#include "../../Tokenizer.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            class Number : public Tokenizer {

            public:
                Number() = default;
                Number(const Number &) = default;
                Number(Number &&) = default;
                Number &operator=(const Number &) = default;
                Number &operator=(Number &&) = default;
                ~Number() = default;

                // Tokenizer
                bool IsValid(char character) override;
                SPtrToken CreateSPtrToken() override;
            };

            SPtrToken Number::CreateSPtrToken();
        }
    }
}


#endif //CLDEPARSER_COMMON_TOKENIZERS_VALUE_H
