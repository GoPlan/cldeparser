//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_COMMON_TOKEN_H
#define CLDEPARSER_COMMON_TOKEN_H

namespace CldeParser {
    namespace Common {

        class Token {

        public:
            Token() = default;
            Token(const Token &) = default;
            Token(Token &&) = default;
            Token &operator=(const Token &) = default;
            Token &operator=(Token &&) = default;
            virtual ~Token() = default;
        };
    }
}


#endif //CLDEPARSER_COMMON_TOKEN_H
