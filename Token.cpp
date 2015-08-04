//
// Created by LE, Duc Anh on 7/29/15.
//

#include "Token.h"
#include "Common/TokenType.h"

namespace CldeParser {

    SPtrToken CreateSPtrToken(int id, const std::string &lexeme) {
        return std::make_shared<Token>(id, lexeme);
    }

    std::string Token::CopyToString() const {
        std::string msg = "<" + Common::CopyToString(_id) + ", " + _lexeme + ">";
        return msg;
    }
}


