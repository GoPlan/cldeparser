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
        }
    }
}


