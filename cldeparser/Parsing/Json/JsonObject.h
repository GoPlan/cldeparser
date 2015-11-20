//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONOBJECT_H
#define CLDEPARSER_PARSING_JSON_JSONOBJECT_H

#include <string>
#include "JsonEntity.h"
#include "JsonValue.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            class JsonObject : public JsonEntity {

            public:
                JsonObject() : JsonEntity{JsonEntityType::Object} { };
                JsonObject(const JsonObject &) = default;
                JsonObject(JsonObject &&) = default;
                JsonObject &operator=(const JsonObject &) = default;
                JsonObject &operator=(JsonObject &&) = default;
                ~JsonObject() = default;

                // IPrintable
                std::string CopyToString() const override;

                // Accessors & Mutators
                SPtrJsonValue GetValue(std::string const &id);
                void SetValue(std::string const &id, SPtrJsonValue const &value);

            protected:
                SPtrJsonValueMap _map;

            };

            using UPtrJsonObject = std::unique_ptr<JsonObject>;
            using SPtrJsonObject = std::shared_ptr<JsonObject>;
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONOBJECT_H
