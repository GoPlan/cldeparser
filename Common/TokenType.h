//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_COMMON_VALUETYPE_H
#define CLDEPARSER_COMMON_VALUETYPE_H

#include <string>

namespace CldeParser {
    namespace Common {

        enum class TokenType {
            BraceOpen = 1,
            BraceClose = 2,
            BracketOpen = 3,
            BracketClose = 4,
            Comma = 5,
            Colon = 6,
            SemiColon = 7,
            String = 8,
            Number = 9,
            Id = 10,
            Space = 11,
            Tab = 12,
            ParenthesesOpen = 13,
            ParenthesesClose = 14
        };

        std::string CopyToString(int id);
    }
}

#endif //CLDEPARSER_COMMON_VALUETYPE_H
