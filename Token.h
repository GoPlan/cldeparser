//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_TOKEN_H
#define CLDEPARSER_TOKEN_H

#include <string>
#include <vector>

namespace CldeParser {

    class Token {

        int _id;
        std::string _lexeme;

    public:
        Token(int id, const std::string &word) : _id{id}, _lexeme{word} { };
        Token(int id, const char *word) : _id{id}, _lexeme{word} { };
        Token(const Token &) = default;
        Token(Token &&) = default;
        Token &operator=(const Token &) = default;
        Token &operator=(Token &&) = default;
        virtual ~Token() = default;
    };

    using SPtrToken = std::shared_ptr<Token>;
    using SPtrTokenVector = std::vector<SPtrToken>;
    using SPtrTokenSet = std::vector<SPtrToken>;

    SPtrToken CreateSPtrToken(int id, const std::string &lexeme);
}


#endif //CLDEPARSER_TOKEN_H
