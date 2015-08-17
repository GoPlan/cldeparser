//
// Created by LE, Duc Anh on 8/10/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONARRAY_H
#define CLDEPARSER_PARSING_JSON_JSONARRAY_H

#include "JsonEntity.h"
#include "JsonValue.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {

            class JsonArray : public JsonEntity {

            public:
                JsonArray() : JsonEntity{JsonEntityType::Array} { };
                JsonArray(const JsonArray &) = default;
                JsonArray(JsonArray &&) = default;
                JsonArray &operator=(const JsonArray &) = default;
                JsonArray &operator=(JsonArray &&) = default;
                virtual ~JsonArray() = default;

                // Locals
                SPtrJsonValueVector &Container() { return _container; }

            protected:
                SPtrJsonValueVector _container;

            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONARRAY_H
