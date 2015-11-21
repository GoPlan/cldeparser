//
// Created by LE, Duc Anh on 8/10/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONARRAY_H
#define CLDEPARSER_PARSING_JSON_JSONARRAY_H

#include "JsonEntity.h"
#include "JsonValue.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            class JsonArray : public JsonEntity {

            public:
                JsonArray() : JsonEntity{JsonEntityType::Array} { };
                JsonArray(const JsonArray &) = default;
                JsonArray(JsonArray &&) = default;
                JsonArray &operator=(const JsonArray &) = default;
                JsonArray &operator=(JsonArray &&) = default;
                ~JsonArray() = default;

                // IPrintable
                std::string CopyToString() const override;

                // Locals
                virtual SPtrJsonValueVector &Container() override { return _container; }
                virtual SPtrJsonValue GetValue(std::string const &id) override;
                virtual void SetValue(std::string const &id, SPtrJsonValue const &value) override;

            protected:
                SPtrJsonValueVector _container;

            };

            using UPtrJsonArray = std::unique_ptr<JsonArray>;
            using SPtrJsonArray = std::shared_ptr<JsonArray>;
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONARRAY_H
