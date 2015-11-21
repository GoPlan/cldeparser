//
// Created by LE, Duc Anh on 8/9/15.
//

#include "JsonObject.h"
#include "JsonException.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            std::string JsonObject::CopyToString() const {

                std::string body{};
                body.reserve(20);

                for (auto &pair : _map) {
                    if (!body.empty())
                        body += ", ";

                    body += pair.first;
                    body += " : ";
                    body += pair.second->CopyToString();
                }

                std::string msg{};
                msg.reserve(20);

                msg += "{";
                msg += body;
                msg += "}";

                return msg;
            }

            SPtrJsonValue JsonObject::GetValue(std::string const &id) {
                auto pair = _map.find(id);
                return pair != _map.end() ? pair->second : SPtrJsonValue{};
            }

            void JsonObject::SetValue(std::string const &id, SPtrJsonValue const &value) {
                _map[id] = value;
            }

            SPtrJsonValueVector &JsonObject::Container() {
                throw JsonException((int) JsonException::JsonExceptionCode::InvalidMethodInType, "Object entity does not support this method");
            }
        }
    }
}


