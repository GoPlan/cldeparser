//
// Created by LE, Duc Anh on 8/13/15.
//

#include "JsonSyntaxModel.h"
#include "JsonFactory.h"
#include "JsonValueFactory.h"
#include "JsonObject.h"
#include "JsonArray.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            void JsonSyntaxModel::Reset() {
                _sptrSyntaxNodeQueue.clear();
                _sptrEntityScopeStack.clear();
            }

            SPtrJsonEntity JsonSyntaxModel::CreateSPtrJsonEnity() {
                auto iterator = _sptrSyntaxNodeQueue.cbegin();
                return createSPtrJsonEntity(iterator);
            }

            SPtrJsonEntity JsonSyntaxModel::createSPtrJsonEntity(SPtrJsonSyntaxNodeIterator &iterator) {

                SPtrJsonEntity sptrJsonEntity;

                if ((*iterator)->id() == (int) JsonSyntaxNodeType::BracketOpen) {
                    sptrJsonEntity = JsonFactory::CreateSPtrJsonArray();
                }
                else if ((*iterator)->id() == (int) JsonSyntaxNodeType::CurlyBraceOpen) {
                    sptrJsonEntity = JsonFactory::CreateSPtrJsonObject();
                }
                else {
                    int code = (int) JsonException::JsonExceptionCode::UnknownSyntaxNode;
                    throw JsonException{code, iterator};
                }

                // Push entity into scope stack
                _sptrEntityScopeStack.push_back(sptrJsonEntity);
                ++iterator;

                for (; iterator != _sptrSyntaxNodeQueue.cend(); ++iterator) {

                    auto &sptrIdNode = *iterator;

                    if ((sptrIdNode->id() == (int) JsonSyntaxNodeType::CurlyBraceClosing
                         || sptrIdNode->id() == (int) JsonSyntaxNodeType::BracketClosing)
                        && !_sptrEntityScopeStack.empty()) {

                        // Pop the (entity) scope stack
                        _sptrEntityScopeStack.pop_back();

                        break;
                    }

                    auto &sptrScopeEntity = _sptrEntityScopeStack.back();

                    switch (sptrScopeEntity->Type()) {

                        case JsonEntityType::Unknown: {
                            int code = (int) JsonException::JsonExceptionCode::UnknownSyntaxNode;
                            throw JsonException{code, iterator};
                        }

                        case JsonEntityType::Object: {
                            auto &object = dynamic_cast<JsonObject &>(*sptrScopeEntity);
                            object.SetValue(sptrIdNode->value(), createSPtrJsonValue(++iterator));
                            break;
                        }

                        case JsonEntityType::Array: {
                            auto &array = dynamic_cast<JsonArray &>(*sptrScopeEntity);
                            array.Container().push_back(createSPtrJsonValue(++iterator));
                            break;
                        }
                    }
                }

                return sptrJsonEntity;
            }

            SPtrJsonValue JsonSyntaxModel::createSPtrJsonValue(SPtrJsonSyntaxNodeIterator &iterator) {

                auto &sptrValueNode = *iterator;
                auto type = (JsonSyntaxNodeType) sptrValueNode->id();

                SPtrJsonValue result;

                switch (type) {

                    case JsonSyntaxNodeType::String: {
                        result = JsonValueFactory::CreateString(sptrValueNode->value());
                        break;
                    }

                    case JsonSyntaxNodeType::Number: {
                        result = JsonValueFactory::CreateDouble(sptrValueNode->value());
                        break;
                    }

                    case JsonSyntaxNodeType::NumberInteger: {
                        result = JsonValueFactory::CreateInteger(sptrValueNode->value());
                        break;
                    }

                    case JsonSyntaxNodeType::BooleanTrue: {
                        result = JsonValueFactory::CreateBooleanTrue();
                        break;
                    }

                    case JsonSyntaxNodeType::BooleanFalse: {
                        result = JsonValueFactory::CreateBooleanFalse();
                        break;
                    }

                    case JsonSyntaxNodeType::Null: {
                        result = JsonValueFactory::CreateNull();
                        break;
                    }

                    case JsonSyntaxNodeType::CurlyBraceOpen: {
                        result = JsonValueFactory::CreateEntityValue(createSPtrJsonEntity(iterator));
                        break;
                    }

                    case JsonSyntaxNodeType::BracketOpen: {
                        result = JsonValueFactory::CreateEntityValue(createSPtrJsonEntity(iterator));
                        break;
                    }

                    default:
                        int code = (int) JsonException::JsonExceptionCode::UnknownValueType;
                        throw JsonException{code, iterator};
                }

                return result;
            }

            std::string JsonSyntaxModel::CopyToString() const {

                std::string msg{};

                for (auto &sptrNode : _sptrSyntaxNodeQueue) {

                    if (!msg.empty())
                        msg += ", ";

                    msg += sptrNode->CopyToString();
                }

                return msg;
            }
        }
    }
}

