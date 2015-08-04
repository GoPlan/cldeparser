//
// Created by LE, Duc Anh on 8/4/15.
//

#include "Id.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            bool Id::IsValid(char character) {
                return _currentState > 0 ? isNumber(character) || isCharacter(character) : isCharacter(character);
            }

            SPtrToken Id::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::Id, _lexeme);
            }

            bool Id::isCharacter(char character) {
                int charvar = (int) character;
                return charvar > 47 && charvar < 58;
            }

            bool Id::isNumber(char character) {
                int charvar = (int) character;
                return (charvar > 40 && charvar < 91) || (charvar > 96 && charvar < 123);
            }
        }
    }
}


