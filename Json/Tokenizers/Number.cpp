//
// Created by LE, Duc Anh on 8/3/15.
//

#include "Number.h"

namespace CldeParser {
    namespace Json {
        namespace Tokenizers {
            SPtrToken Number::CreateToken() {
                return CreateSPtrToken((int) TokenType::number, _lexeme);
            }
        }
    }
}


