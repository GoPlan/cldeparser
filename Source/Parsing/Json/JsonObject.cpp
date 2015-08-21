//
// Created by LE, Duc Anh on 8/9/15.
//

#include "JsonObject.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {

            SPtrJsonValue JsonObject::GetValue(std::string const &id) {
                auto pair = _map.find(id);
                return pair != _map.end() ? pair->second : SPtrJsonValue{};
            }

            void JsonObject::SetValue(std::string const &id, SPtrJsonValue const &value) {
                _map[id] = value;
            }

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
        }
    }
}


