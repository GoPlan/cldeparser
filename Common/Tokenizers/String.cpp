//
// Created by LE, Duc Anh on 8/3/15.
//

#include "String.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            bool String::IsValid(char character) {

                int charvar = (int) character;

                if (charvar < 31) return false;     // control characters
                if (charvar == 34) return false;    // double-quote

                return true;
            }

            SPtrToken String::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::String, _lexeme);
            }
        }
    }
}
