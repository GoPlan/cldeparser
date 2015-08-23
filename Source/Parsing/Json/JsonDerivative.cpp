//
// Created by LE, Duc Anh on 8/9/15.
//

#include "JsonDerivative.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            JsonDerivative::JsonDerivative() :
                    _sptrSyntaxModel{std::make_shared<JsonSyntaxModel>()} {
                //
            }

            void JsonDerivative::matchBracketOpen(SPtrTokenVectorIterator &iterator) {

                JsonSyntaxNodeType type = (JsonSyntaxNodeType) (*iterator)->id();

                if (type != JsonSyntaxNodeType::BracketOpen) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    std::string msg{"Unexpected token is found " + (*iterator)->CopyToString()};
                    throw Exceptions::ParserException{code, msg};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchBracketClosing(SPtrTokenVectorIterator &iterator) {

                JsonSyntaxNodeType type = (JsonSyntaxNodeType) (*iterator)->id();

                if (type != JsonSyntaxNodeType::BracketClosing) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    std::string msg{"Unexpected token is found " + (*iterator)->CopyToString()};
                    throw Exceptions::ParserException{code, msg};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchCurlyBraceOpen(SPtrTokenVectorIterator &iterator) {

                JsonSyntaxNodeType type = (JsonSyntaxNodeType) (*iterator)->id();

                if (type != JsonSyntaxNodeType::CurlyBraceOpen) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    std::string msg{"Unexpected token is found " + (*iterator)->CopyToString()};
                    throw Exceptions::ParserException{code, msg};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchCurlyBraceClosing(SPtrTokenVectorIterator &iterator) {

                JsonSyntaxNodeType type = (JsonSyntaxNodeType) (*iterator)->id();

                if (type != JsonSyntaxNodeType::CurlyBraceClosing) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    std::string msg{"Unexpected token is found " + (*iterator)->CopyToString()};
                    throw Exceptions::ParserException{code, msg};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchComma(SPtrTokenVectorIterator &iterator) {

                JsonSyntaxNodeType type = (JsonSyntaxNodeType) (*iterator)->id();

                if (type != JsonSyntaxNodeType::Comma) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    std::string msg{"Unexpected token is found " + (*iterator)->CopyToString()};
                    throw Exceptions::ParserException{code, msg};
                }

                ++iterator;
            }

            void JsonDerivative::matchColon(SPtrTokenVectorIterator &iterator) {

                JsonSyntaxNodeType type = (JsonSyntaxNodeType) (*iterator)->id();

                if (type != JsonSyntaxNodeType::Colon) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    std::string msg{"Unexpected token is found " + (*iterator)->CopyToString()};
                    throw Exceptions::ParserException{code, msg};
                }

                ++iterator;
            }

            void JsonDerivative::matchId(SPtrTokenVectorIterator &iterator) {

                JsonSyntaxNodeType type = (JsonSyntaxNodeType) (*iterator)->id();

                if (type != JsonSyntaxNodeType::Id) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    std::string msg{"Unexpected token is found " + (*iterator)->CopyToString()};
                    throw Exceptions::ParserException{code, msg};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchString(SPtrTokenVectorIterator &iterator) {

                JsonSyntaxNodeType type = (JsonSyntaxNodeType) (*iterator)->id();

                if (type != JsonSyntaxNodeType::String) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    std::string msg{"Unexpected token is found " + (*iterator)->CopyToString()};
                    throw Exceptions::ParserException{code, msg};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchNumberInteger(SPtrTokenVectorIterator &iterator) {

                JsonSyntaxNodeType type = (JsonSyntaxNodeType) (*iterator)->id();

                if (type != JsonSyntaxNodeType::NumberInteger) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    std::string msg{"Unexpected token is found " + (*iterator)->CopyToString()};
                    throw Exceptions::ParserException{code, msg};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchNumber(SPtrTokenVectorIterator &iterator) {

                JsonSyntaxNodeType type = (JsonSyntaxNodeType) (*iterator)->id();

                if (type != JsonSyntaxNodeType::Number) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    std::string msg{"Unexpected token is found " + (*iterator)->CopyToString()};
                    throw Exceptions::ParserException{code, msg};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchTrue(SPtrTokenVectorIterator &iterator) {

                JsonSyntaxNodeType type = (JsonSyntaxNodeType) (*iterator)->id();

                if (type != JsonSyntaxNodeType::BooleanTrue) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    std::string msg{"Unexpected token is found " + (*iterator)->CopyToString()};
                    throw Exceptions::ParserException{code, msg};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchFalse(SPtrTokenVectorIterator &iterator) {

                JsonSyntaxNodeType type = (JsonSyntaxNodeType) (*iterator)->id();

                if (type != JsonSyntaxNodeType::BooleanFalse) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    std::string msg{"Unexpected token is found " + (*iterator)->CopyToString()};
                    throw Exceptions::ParserException{code, msg};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchNull(SPtrTokenVectorIterator &iterator) {

                JsonSyntaxNodeType type = (JsonSyntaxNodeType) (*iterator)->id();

                if (type != JsonSyntaxNodeType::Null) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    std::string msg{"Unexpected token is found " + (*iterator)->CopyToString()};
                    throw Exceptions::ParserException{code, msg};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            bool JsonDerivative::CoreDerive(SPtrTokenVectorIterator &sptrTokenIterator) {
                return json(sptrTokenIterator);
            }

            bool JsonDerivative::IsFirst(const SPtrToken &token) {
                return token->id() == (int) JsonSyntaxNodeType::CurlyBraceOpen
                       || token->id() == (int) JsonSyntaxNodeType::BracketOpen;
            }

            bool JsonDerivative::json(SPtrTokenVectorIterator &iterator) {

                JsonSyntaxNodeType type = (JsonSyntaxNodeType) (*iterator)->id();

                if (type == JsonSyntaxNodeType::CurlyBraceOpen
                    || type == JsonSyntaxNodeType::CurlyBraceClosing) {
                    object_stmt(iterator);
                }

                else if (type == JsonSyntaxNodeType::BracketOpen
                         || type == JsonSyntaxNodeType::BracketClosing) {
                    array_stmt(iterator);
                }

                else {
                    return false;
                }

                return true;
            }

            void JsonDerivative::object_stmt(SPtrTokenVectorIterator &iterator) {
                matchCurlyBraceOpen(iterator);
                object(iterator);
                matchCurlyBraceClosing(iterator);
            }

            void JsonDerivative::array_stmt(SPtrTokenVectorIterator &iterator) {
                matchBracketOpen(iterator);
                array(iterator);
                matchBracketClosing(iterator);
            }

            void JsonDerivative::object(SPtrTokenVectorIterator &iterator) {

                auto type = (JsonSyntaxNodeType) (*iterator)->id();

                if (type == JsonSyntaxNodeType::Id || type == JsonSyntaxNodeType::String) {
                    pair(iterator);
                }

                if ((JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::Comma) {
                    pair_add(iterator);
                }
            }

            void JsonDerivative::pair(SPtrTokenVectorIterator &iterator) {
                name(iterator);
                matchColon(iterator);
                value(iterator);
            }

            void JsonDerivative::name(SPtrTokenVectorIterator &iterator) {

                if ((JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::Id) {
                    matchId(iterator);
                }

                if ((JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::String) {
                    matchString(iterator);
                }
            }

            void JsonDerivative::pair_add(SPtrTokenVectorIterator &iterator) {

                matchComma(iterator);
                pair(iterator);

                if ((JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::Comma) {
                    pair_add(iterator);
                }
            }

            void JsonDerivative::array(SPtrTokenVectorIterator &iterator) {

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((int) JsonSyntaxNodeType::Id,
                                                                                 std::string{}));
                value(iterator);

                if ((JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::Comma) {
                    value_add(iterator);
                }
            }

            void JsonDerivative::value_add(SPtrTokenVectorIterator &iterator) {

                matchComma(iterator);

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((int) JsonSyntaxNodeType::Id,
                                                                                 std::string{}));

                value(iterator);

                if ((JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::Comma) {
                    value_add(iterator);
                }
            }

            void JsonDerivative::value(SPtrTokenVectorIterator &iterator) {

                JsonSyntaxNodeType type = (JsonSyntaxNodeType) (*iterator)->id();

                if (type == JsonSyntaxNodeType::String) {
                    matchString(iterator);
                }

                else if (type == JsonSyntaxNodeType::Number) {
                    matchNumber(iterator);
                }

                else if (type == JsonSyntaxNodeType::NumberInteger) {
                    matchNumberInteger(iterator);
                }

                else if (type == JsonSyntaxNodeType::BooleanTrue) {
                    matchTrue(iterator);
                }

                else if (type == JsonSyntaxNodeType::BooleanFalse) {
                    matchFalse(iterator);
                }

                else if (type == JsonSyntaxNodeType::Null) {
                    matchNull(iterator);
                }

                else if (type == JsonSyntaxNodeType::CurlyBraceOpen) {
                    object_stmt(iterator);
                }

                else if (type == JsonSyntaxNodeType::BracketOpen) {
                    array_stmt(iterator);
                }

                else {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnknownValueType;
                    throw Exceptions::ParserException{code, std::string{}};
                }
            }

            SPtrSyntaxModel JsonDerivative::SyntaxModel() {
                return _sptrSyntaxModel;
            }

            void JsonDerivative::Reset() {
                _sptrSyntaxModel->Reset();
            }
        }
    }
}

