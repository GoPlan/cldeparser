//
// Created by LE, Duc Anh on 8/4/15.
//

#include "TokenType.h"

namespace CldeParser {
    namespace Scanning {
        std::string CopyToString(int id) {
            switch ((TokenType) id) {
                case TokenType::CurlyBraceOpen:
                    return "CurlyBraceOpen";
                case TokenType::CurlyBraceClosing:
                    return "CurlyBraceClosing";
                case TokenType::BracketOpen:
                    return "BracketOpen";
                case TokenType::BracketClosing:
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
                case TokenType::ParenthesesOpen:
                    return "ParenthesesOpen";
                case TokenType::ParenthesesClosing:
                    return "ParenthesesClosing";
                case TokenType::SquareBracketOpen:
                    return "SquareBracketOpen";
                case TokenType::SquareBracketClosing:
                    return "SquareBracketClosing";
                case TokenType::AngleBracketOpen:
                    return "AngleBracketOpen";
                case TokenType::AngleBracketClosing:
                    return "AngleBracketClosing";
                case TokenType::BackwardSlash:
                    return "BackwardSlash";
                case TokenType::ForwardSlash:
                    return "ForwardSlash";
                case TokenType::Adding:
                    return "Adding";
                case TokenType::Subtracting:
                    return "Subtracting";
                case TokenType::Multiplication:
                    return "Multiplication";
                case TokenType::Division:
                    return "Division";
            }
        }
    }
}