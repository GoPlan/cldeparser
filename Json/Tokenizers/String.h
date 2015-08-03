//
// Created by LE, Duc Anh on 8/3/15.
//

#ifndef CLDEPARSER_JSON_TOKENIZERS_STRING_H
#define CLDEPARSER_JSON_TOKENIZERS_STRING_H

#include "../TokenType.h"
#include "../../Tokenizer.h"

namespace CldeParser {
    namespace Json {
        namespace Tokenizers {

            class String : public Tokenizer {

            public:
                String() = default;
                String(const String &) = default;
                String(String &&) = default;
                String &operator=(const String &) = default;
                String &operator=(String &&) = default;
                ~String() = default;

                // Tokenizer
                virtual SPtrToken CreateToken() override;
            };
        }
    }
}


#endif //CLDEPARSER_JSON_TOKENIZERS_STRING_H
