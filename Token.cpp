//
// Created by LE, Duc Anh on 7/29/15.
//

#include "Token.h"

namespace CldeParser {

    Token::Token(const std::string &word, int id)
            : _lexeme{word}, _id{id} {
        //
    }

    Token::Token(const char *word, int id)
            : _lexeme{word}, _id{id} {
        //
    }

    SPtrToken Create(const std::string &lexeme, int id) {
        return std::make_shared<Token>(lexeme, id);
    }
}


