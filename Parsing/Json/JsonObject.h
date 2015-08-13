//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONOBJECT_H
#define CLDEPARSER_PARSING_JSON_JSONOBJECT_H

#include <string>
#include "JsonEntity.h"
#include "JsonValue.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {

            using SPtrJsonValueMap = std::unordered_map<std::string, SPtrJsonValue>;

            class JsonObject : public JsonEntity {

            public:
                JsonObject() = default;
                JsonObject(const JsonObject &) = default;
                JsonObject(JsonObject &&) = default;
                JsonObject &operator=(const JsonObject &) = default;
                JsonObject &operator=(JsonObject &&) = default;
                virtual ~JsonObject() = default;

                // Accessors & Mutators
                SPtrJsonValue GetValue(std::string const &id);
                void SetValue(std::string const &id, SPtrJsonValue const &value);

            protected:
                SPtrJsonValueMap _map;

            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONOBJECT_H
