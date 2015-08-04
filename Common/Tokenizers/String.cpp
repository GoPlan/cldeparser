//
// Created by LE, Duc Anh on 8/3/15.
//

#include "String.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            SPtrToken String::CreateSPtrToken() {
                return CreateSPtrToken((int) TokenType::string, _lexeme);
            }

            bool String::IsValid(char character) {
                return true;
            }
        }
    }
}
