//
// Created by LE, Duc Anh on 8/4/15.
//

#include "TokenType.h"

namespace CldeParser {
    namespace Scanning {
        std::string CopyToString(int id) {
            switch ((TokenType) id) {
                case TokenType::BraceOpen:
                    return "BraceOpen";
                case TokenType::BraceClose:
                    return "BraceClose";
                case TokenType::BracketOpen:
                    return "BracketOpen";
                case TokenType::BracketClose:
                    return "BracketClose";
                case TokenType::Comma:
                    return "Comma";
                case TokenType::Colon:
                    return "Colon";
                case TokenType::SemiColon:
                    return "SemiColon";
                case TokenType::String:
                    return "String";
                case TokenType::Number:
                    return "Number";
                case TokenType::Id:
                    return "Id";
                case TokenType::Space:
                    return "Space";
                case TokenType::Tab:
                    return "Tab";
            }
        }
    }
}