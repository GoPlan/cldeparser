//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_TOKEN_H
#define CLDEPARSER_TOKEN_H

#include <string>
#include <vector>

namespace CldeParser {

    class Token {

        std::string _lexeme;
        int _id;

    public:
        Token(const std::string &word, int id);
        Token(const char *word, int id);
        Token(const Token &) = default;
        Token(Token &&) = default;
        Token &operator=(const Token &) = default;
        Token &operator=(Token &&) = default;
        virtual ~Token() = default;
    };

    using SPtrToken = std::shared_ptr<Token>;
    using SPtrTokenVector = std::vector<SPtrToken>;

    SPtrToken Create(const std::string &lexeme, int id);
}


#endif //CLDEPARSER_TOKEN_H
