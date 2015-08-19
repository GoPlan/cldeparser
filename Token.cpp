//
// Created by LE, Duc Anh on 7/29/15.
//

#include "Token.h"
#include "Scanning/TokenType.h"

namespace CldeParser {

    SPtrToken CreateSPtrToken(int id, const std::string &lexeme) {
        return std::make_shared<Token>(id, lexeme);
    }

    SPtrToken CreateSPtrToken(int id, int index, std::string const &lexeme) {
        return std::make_shared<Token>(id, index, lexeme);
    }

    std::string Token::CopyToString() const {
        std::string msg{"<" + Scanning::CopyToString(_id) + ", " + _lexeme + ">"};
        return msg;
    }
}


