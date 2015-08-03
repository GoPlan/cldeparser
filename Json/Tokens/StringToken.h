//
// Created by LE, Duc Anh on 8/3/15.
//

#ifndef CLDEPARSER_JSON_TOKENS_STRING_H
#define CLDEPARSER_JSON_TOKENS_STRING_H

#include "../../Token.h"

namespace CldeParser {
    namespace Json {
        namespace Tokens {

            class StringToken : public Token {

            public:
                StringToken() = default;
                StringToken(const StringToken &) = default;
                StringToken(StringToken &&) = default;
                StringToken &operator=(const StringToken &) = default;
                StringToken &operator=(StringToken &&) = default;
                virtual ~StringToken() = default;

                // Token
                static bool Validate(char character);
            };
        }
    }
}


#endif //CLDEPARSER_JSON_TOKENS_STRING_H
