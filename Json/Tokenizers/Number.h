//
// Created by LE, Duc Anh on 8/3/15.
//

#ifndef CLDEPARSER_JSON_TOKENIZERS_VALUE_H
#define CLDEPARSER_JSON_TOKENIZERS_VALUE_H

#include "../../Tokenizer.h"
#include "../TokenType.h"

namespace CldeParser {
    namespace Json {
        namespace Tokenizers {

            class Number : public Tokenizer {

            public:
                Number() = default;
                Number(const Number &) = default;
                Number(Number &&) = default;
                Number &operator=(const Number &) = default;
                Number &operator=(Number &&) = default;
                virtual ~Number() = default;

                // Tokenizer

                virtual SPtrToken CreateToken() override;
            };

            SPtrToken Number::CreateToken();
        }
    }
}


#endif //CLDEPARSER_JSON_TOKENIZERS_VALUE_H
