//
// Created by LE, Duc Anh on 8/3/15.
//

#include "Number.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            bool Number::IsValid(char character) {
                int charvar = (int) character;
                return (charvar > 40 && charvar < 91) || (charvar > 96 && charvar < 123);
            }

            SPtrToken Number::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::Number, _lexeme);
            }
        }
    }
}


