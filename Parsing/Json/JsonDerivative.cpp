//
// Created by LE, Duc Anh on 8/9/15.
//

#include "JsonDerivative.h"
#include "../../Scanning/TokenType.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {

            void JsonDerivative::matchBracketOpen(const SPtrTokenSetIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::BracketOpen) {
                    // TODO: exception
                }

                ++iterator;
            }

            void JsonDerivative::matchBracketClosing(const SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::BracketClosing) {
                    // TODO: exception
                }

                ++iterator;

            }

            void JsonDerivative::matchCurlyBraceOpen(const SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::CurlyBraceOpen) {
                    // TODO: exception
                }

                ++iterator;

            }

            void JsonDerivative::matchCurlyBraceClosing(const SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::CurlyBraceClosing) {
                    // TODO: exception
                }

                ++iterator;

            }

            void JsonDerivative::matchComma(const SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::Comma) {
                    // TODO: exception
                }

                ++iterator;

            }

            void JsonDerivative::matchColon(const SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::Colon) {
                    // TODO: exception
                }

                ++iterator;

            }

            void JsonDerivative::matchId(const SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type != Scanning::TokenType::Id) {
                    // TODO: exception
                }

                ++iterator;

            }

            bool JsonDerivative::Derive(const SPtrTokenVector &sptrTokenVector) {
                return json(sptrTokenVector.cbegin());
            }

            bool JsonDerivative::json(const SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type == Scanning::TokenType::BracketOpen
                    || type == Scanning::TokenType::BracketClosing) {
                    object_stmt(iterator);
                }

                else if (type == Scanning::TokenType::SquareBracketOpen
                         || type == Scanning::TokenType::SquareBracketClosing) {
                    array_stmt(iterator);
                }

                else {
                    // TODO: exception
                }

                return true;
            }

            void JsonDerivative::object_stmt(const SPtrTokenVectorIterator &iterator) {

                // Matching
                matchCurlyBraceOpen(iterator);
                object(iterator);
                matchCurlyBraceClosing(iterator);

                // TODO: syntax node
            }

            void JsonDerivative::object(const SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();

                if (type == Scanning::TokenType::Id) {
                    pair(iterator);
                }

                else if (type == Scanning::TokenType::Comma) {
                    pair_add(iterator);
                }

                else {
                    // TODO: exception
                }
            }

            void JsonDerivative::pair(const SPtrTokenVectorIterator &iterator) {
                matchId(iterator);
                matchColon(iterator);
                value(iterator);
            }

            void JsonDerivative::pair_add(const SPtrTokenVectorIterator &iterator) {

            }

            void JsonDerivative::array_stmt(const SPtrTokenVectorIterator &iterator) {

            }

            void JsonDerivative::array(const SPtrTokenVectorIterator &iterator) {

            }

            void JsonDerivative::value_add(const SPtrTokenVectorIterator &iterator) {

            }

            void JsonDerivative::value(const SPtrTokenVectorIterator &iterator) {

                Scanning::TokenType type = (Scanning::TokenType) (*iterator)->id();


            }
        }
    }
}

