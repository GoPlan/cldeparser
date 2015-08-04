//
// Created by LE, Duc Anh on 8/3/15.
//

#include "Number.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {
            SPtrToken Number::CreateSPtrToken() {
                return CreateSPtrToken((int) TokenType::number, _lexeme);
            }
        }
    }
}


