//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_SCANNER_VALUETYPE_H
#define CLDEPARSER_SCANNER_VALUETYPE_H

#include <string>

namespace CldeParser {
    namespace Scanning {

        enum class TokenType {
            BraceOpen = 1,
            BraceClosing = 2,
            BracketOpen = 3,
            BracketClosing = 4,
            Comma = 5,
            Colon = 6,
            SemiColon = 7,
            String = 8,
            Number = 9,
            Id = 10,
            Space = 11,
            Tab = 12,
            ParenthesesOpen = 13,
            ParenthesesClosing = 14,
            SquareBracketOpen = 15,
            SquareBracketClosing = 16,
            AngleBracketOpen = 17,
            AngleBracketClosing = 18,
            BackwardSlash = 19,
            ForwardSlash = 20
        };

        std::string CopyToString(int id);
    }
}

#endif //CLDEPARSER_SCANNER_VALUETYPE_H
