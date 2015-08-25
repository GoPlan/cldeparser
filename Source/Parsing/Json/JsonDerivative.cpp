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

            bool JsonDerivative::isObjectFirstFollow(SPtrTokenVectorIterator &iterator) {

                if ((JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::BracketOpen) {
                    return true;
                }

                if ((JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::CurlyBraceOpen) {
                    return true;
                }

                if ((JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::String) {
                    return true;
                }

                if ((JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::BooleanFalse) {
                    return true;
                }

                if ((JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::BooleanTrue) {
                    return true;
                }

                if ((JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::Null) {
                    return true;
                }

                if ((JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::Number) {
                    return true;
                }

                if ((JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::NumberInteger) {
                    return true;
                }

                return false;
            }

            void JsonDerivative::matchBracketOpen(SPtrTokenVectorIterator &iterator) {

                if ((JsonSyntaxNodeType) (*iterator)->id() != JsonSyntaxNodeType::BracketOpen) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    throw Exceptions::ParserException{code, iterator};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchBracketClosing(SPtrTokenVectorIterator &iterator) {

                if ((JsonSyntaxNodeType) (*iterator)->id() != JsonSyntaxNodeType::BracketClosing) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    throw Exceptions::ParserException{code, iterator};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchCurlyBraceOpen(SPtrTokenVectorIterator &iterator) {

                if ((JsonSyntaxNodeType) (*iterator)->id() != JsonSyntaxNodeType::CurlyBraceOpen) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    throw Exceptions::ParserException{code, iterator};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchCurlyBraceClosing(SPtrTokenVectorIterator &iterator) {

                if ((JsonSyntaxNodeType) (*iterator)->id() != JsonSyntaxNodeType::CurlyBraceClosing) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    throw Exceptions::ParserException{code, iterator};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchComma(SPtrTokenVectorIterator &iterator) {

                if ((JsonSyntaxNodeType) (*iterator)->id() != JsonSyntaxNodeType::Comma) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    throw Exceptions::ParserException{code, iterator};
                }

                ++iterator;
            }

            void JsonDerivative::matchColon(SPtrTokenVectorIterator &iterator) {

                if ((JsonSyntaxNodeType) (*iterator)->id() != JsonSyntaxNodeType::Colon) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    throw Exceptions::ParserException{code, iterator};
                }

                ++iterator;
            }

            void JsonDerivative::matchId(SPtrTokenVectorIterator &iterator) {

                if ((JsonSyntaxNodeType) (*iterator)->id() != JsonSyntaxNodeType::Id) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    throw Exceptions::ParserException{code, iterator};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchString(SPtrTokenVectorIterator &iterator) {

                if ((JsonSyntaxNodeType) (*iterator)->id() != JsonSyntaxNodeType::String) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    throw Exceptions::ParserException{code, iterator};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchNumberInteger(SPtrTokenVectorIterator &iterator) {

                if ((JsonSyntaxNodeType) (*iterator)->id() != JsonSyntaxNodeType::NumberInteger) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    throw Exceptions::ParserException{code, iterator};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchNumber(SPtrTokenVectorIterator &iterator) {

                if ((JsonSyntaxNodeType) (*iterator)->id() != JsonSyntaxNodeType::Number) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    throw Exceptions::ParserException{code, iterator};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchTrue(SPtrTokenVectorIterator &iterator) {

                if ((JsonSyntaxNodeType) (*iterator)->id() != JsonSyntaxNodeType::BooleanTrue) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    throw Exceptions::ParserException{code, iterator};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchFalse(SPtrTokenVectorIterator &iterator) {

                if ((JsonSyntaxNodeType) (*iterator)->id() != JsonSyntaxNodeType::BooleanFalse) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    throw Exceptions::ParserException{code, iterator};
                }

                _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((*iterator)->id(),
                                                                                 (*iterator)->lexeme()));

                ++iterator;
            }

            void JsonDerivative::matchNull(SPtrTokenVectorIterator &iterator) {

                if ((JsonSyntaxNodeType) (*iterator)->id() != JsonSyntaxNodeType::Null) {
                    int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
                    throw Exceptions::ParserException{code, iterator};
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

                if ((JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::CurlyBraceOpen
                    || (JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::CurlyBraceClosing) {
                    return object_stmt(iterator);
                }

                if ((JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::BracketOpen
                    || (JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::BracketClosing) {
                    return array_stmt(iterator);
                }

                return false;
            }

            bool JsonDerivative::object_stmt(SPtrTokenVectorIterator &iterator) {

                matchCurlyBraceOpen(iterator);
                object(iterator);
                matchCurlyBraceClosing(iterator);

                return true;
            }

            bool JsonDerivative::array_stmt(SPtrTokenVectorIterator &iterator) {

                matchBracketOpen(iterator);
                array(iterator);
                matchBracketClosing(iterator);

                return true;
            }

            void JsonDerivative::object(SPtrTokenVectorIterator &iterator) {

                if ((JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::Id
                    || (JsonSyntaxNodeType) (*iterator)->id() == JsonSyntaxNodeType::String) {
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

                if (isObjectFirstFollow(iterator)) {

                    _sptrSyntaxModel->_sptrSyntaxNodeQueue
                                    .push_back(JsonFactory::CreateSPtrJsonSyntaxNode((int) JsonSyntaxNodeType::Id,
                                                                                     std::string{}));
                    value(iterator);
                }

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
                    throw Exceptions::ParserException{code, iterator};
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

