//
// Created by LE, Duc Anh on 8/9/15.
//

#include "JsonDerivative.h"
#include "../../Scanning/TokenType.h"
#include "../../Exceptions/Exception.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {

            void JsonDerivative::matchBracketOpen(SPtrTokenSetIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::BracketOpen) {
                    std::string msg{"Unexpected token is found"};
                    throw Exceptions::Exception{msg};
                }

                ++iterator;
            }

            void JsonDerivative::matchBracketClosing(SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::BracketClosing) {
                    std::string msg{"Unexpected token is found"};
                    throw Exceptions::Exception{msg};
                }

                ++iterator;
            }

            void JsonDerivative::matchCurlyBraceOpen(SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::CurlyBraceOpen) {
                    std::string msg{"Unexpected token is found"};
                    throw Exceptions::Exception{msg};
                }

                ++iterator;
            }

            void JsonDerivative::matchCurlyBraceClosing(SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::CurlyBraceClosing) {
                    std::string msg{"Invalid token is found"};
                    throw Exceptions::Exception{msg};
                }

                ++iterator;

            }

            void JsonDerivative::matchComma(SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::Comma) {
                    std::string msg{"Invalid token is found"};
                    throw Exceptions::Exception{msg};
                }

                ++iterator;
            }

            void JsonDerivative::matchColon(SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::Colon) {
                    std::string msg{"Invalid token is found"};
                    throw Exceptions::Exception{msg};
                }

                ++iterator;
            }

            void JsonDerivative::matchId(SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::Id) {
                    std::string msg{"Invalid token is found"};
                    throw Exceptions::Exception{msg};
                }

                ++iterator;
            }

            void JsonDerivative::matchString(SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::String) {
                    std::string msg{"Invalid token is found"};
                    throw Exceptions::Exception{msg};
                }

                ++iterator;
            }

            void JsonDerivative::matchNumber(SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::Number) {
                    std::string msg{"Invalid token is found"};
                    throw Exceptions::Exception{msg};
                }

                ++iterator;
            }

            void JsonDerivative::matchTrue(SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::BoolTrue) {
                    std::string msg{"Invalid token is found"};
                    throw Exceptions::Exception{msg};
                }

                ++iterator;
            }

            void JsonDerivative::matchFalse(SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::BoolFalse) {
                    std::string msg{"Invalid token is found"};
                    throw Exceptions::Exception{msg};
                }

                ++iterator;
            }

            void JsonDerivative::matchNull(SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::Null) {
                    std::string msg{"Invalid token is found"};
                    throw Exceptions::Exception{msg};
                }

                ++iterator;
            }

            bool JsonDerivative::CoreDerive(SPtrTokenVectorIterator &sptrTokenIterator) {
                return json(sptrTokenIterator);
            }

            bool JsonDerivative::IsFirst(const SPtrToken &token) {
                return token->id() == (int) Scanning::TokenType::CurlyBraceOpen
                       || token->id() == (int) Scanning::TokenType::BracketOpen;
            }

            bool JsonDerivative::json(SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type == Scanning::TokenType::CurlyBraceOpen
                    || type == Scanning::TokenType::CurlyBraceClosing) {
                    object_stmt(iterator);
                }

                else if (type == Scanning::TokenType::SquareBracketOpen
                         || type == Scanning::TokenType::SquareBracketClosing) {
                    array_stmt(iterator);
                }

                else {
                    std::string msg{};
                    throw Exceptions::Exception{msg};
                }

                return true;
            }

            void JsonDerivative::object_stmt(SPtrTokenVectorIterator &iterator) {

                // Matching
                matchCurlyBraceOpen(iterator);
                object(iterator);
                matchCurlyBraceClosing(iterator);

                // TODO: syntax node
            }

            void JsonDerivative::array_stmt(SPtrTokenVectorIterator &iterator) {

            }

            void JsonDerivative::object(SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type == Scanning::TokenType::Id) {
                    pair(iterator);
                }

                else if (type == Scanning::TokenType::Comma) {
                    pair_add(iterator);
                }

                else {
                    std::string msg{};
                    throw Exceptions::Exception{msg};
                }
            }

            void JsonDerivative::pair(SPtrTokenVectorIterator &iterator) {
                matchId(iterator);
                matchColon(iterator);
                value(iterator);
            }

            void JsonDerivative::pair_add(SPtrTokenVectorIterator &iterator) {

                matchComma(iterator);
                pair(iterator);

                if ((Scanning::TokenType) (*iterator)->id() == Scanning::TokenType::Comma) {
                    pair_add(iterator);
                }
            }

            void JsonDerivative::array(SPtrTokenVectorIterator &iterator) {

            }

            void JsonDerivative::value_add(SPtrTokenVectorIterator &iterator) {

            }

            void JsonDerivative::value(SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type == Scanning::TokenType::String) {
                    matchString(iterator);
                }
                else if (type == Scanning::TokenType::Number) {
                    matchNumber(iterator);
                }
                else if (type == Scanning::TokenType::BoolTrue) {
                    matchTrue(iterator);
                }
                else if (type == Scanning::TokenType::BoolFalse) {
                    matchFalse(iterator);
                }
                else if (type == Scanning::TokenType::Null) {
                    matchNull(iterator);
                }
                else if (type == Scanning::TokenType::CurlyBraceOpen) {
                    object_stmt(iterator);
                }
                else if (type == Scanning::TokenType::BracketOpen) {
                    array_stmt(iterator);
                }
                else {
                    std::string msg{};
                    throw Exceptions::Exception{msg};
                }
            }
        }
    }
}

