//
// Created by LE, Duc Anh on 8/13/15.
//

#include <iostream>
#include "JsonSyntaxModel.h"
#include "JsonFactory.h"
#include "../../Scanning/TokenType.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {

            void JsonSyntaxModel::Reset() {
                _sptrSyntaxNodeStack.clear();
                _sptrEntityScopeStack.clear();
            }

            SPtrJsonEntity JsonSyntaxModel::CreateSPtrJsonEnity() {
                auto iterator = _sptrSyntaxNodeStack.cbegin();
                _root = createSPtrJsonEntity(iterator);
                return _root;
            }

            SPtrJsonEntity JsonSyntaxModel::createSPtrJsonEntity(SPtrJsonSyntaxNodeIterator &iterator) {

                SPtrJsonEntity _sptrEntity;

                if ((*iterator)->id() == (int) JsonSyntaxNodeType::ArrayOpen) {
                    _sptrEntity = JsonFactory::CreateSPtrJsonArray();
                }
                else if ((*iterator)->id() == (int) JsonSyntaxNodeType::ObjectOpen) {
                    _sptrEntity = JsonFactory::CreateSPtrJsonObject();
                }
                else {
                    //TODO: exception
                }

                // Push _root into scope stack
                _sptrEntityScopeStack.push_back(_sptrEntity);
                ++iterator;

                for (; iterator != _sptrSyntaxNodeStack.cend(); ++iterator) {

                    auto &sptrIdNode = *iterator;

                    if ((sptrIdNode->id() == (int) Scanning::TokenType::CurlyBraceClosing
                         || sptrIdNode->id() == (int) Scanning::TokenType::BracketClosing) && !_sptrEntityScopeStack.empty()) {

                        // Pop the scope stack
                        _sptrEntityScopeStack.pop_back();
                        continue;
                    }

                    auto &sptrScopeEntity = _sptrEntityScopeStack.back();

                    switch (sptrScopeEntity->Type()) {

                        case JsonEntityType::Unknown: {
                            //TODO: exception
                            break;
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

                return _sptrEntity;
            }

            SPtrJsonValue JsonSyntaxModel::createSPtrJsonValue(SPtrJsonSyntaxNodeIterator &iterator) {

                auto &sptrValueNode = *iterator;
                auto type = (Scanning::TokenType) sptrValueNode->id();

                SPtrJsonValue result;

                switch (type) {

                    case Scanning::TokenType::String: {
                        break;
                    }

                    case Scanning::TokenType::Number: {
                        break;
                    }

                    case Scanning::TokenType::BoolTrue: {
                        break;
                    }

                    case Scanning::TokenType::BoolFalse: {
                        break;
                    }

                    case Scanning::TokenType::Null: {
                        break;
                    }

                    case Scanning::TokenType::CurlyBraceOpen: {
                        SPtrJsonEntity sptrJsonEntity = JsonFactory::CreateSPtrJsonObject();
                        _sptrEntityScopeStack.push_back(sptrJsonEntity);
                        break;
                    }

                    case Scanning::TokenType::BracketOpen: {
                        SPtrJsonEntity sptrJsonEntity = JsonFactory::CreateSPtrJsonArray();
                        _sptrEntityScopeStack.push_back(sptrJsonEntity);
                        break;
                    }

                    default:
                        //TODO: exception
                        break;
                }

                return result;
            }
        }
    }
}

