//
// Created by LE, Duc Anh on 8/3/15.
//

#include "String.h"

namespace CldeParser {
    namespace Json {
        namespace Tokenizers {
            SPtrToken String::CreateToken() {
                return CreateSPtrToken((int) TokenType::string, _lexeme);
            }
        }
    }
}
