//
// Created by LE, Duc Anh on 7/29/15.
//

#include "Token.h"

namespace CldeParser {

    SPtrToken CreateSPtrToken(int id, const std::string &lexeme) {
        return std::make_shared<Token>(id, lexeme);
    }
}


