//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONOBJECT_H
#define CLDEPARSER_PARSING_JSON_JSONOBJECT_H

#include <string>
#include "JsonValue.h"
#include "JsonEntity.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {

            class JsonObject : public JsonEntity {

            public:
                JsonObject() = default;
                JsonObject(const JsonObject &) = default;
                JsonObject(JsonObject &&) = default;
                JsonObject &operator=(const JsonObject &) = default;
                JsonObject &operator=(JsonObject &&) = default;
                virtual ~JsonObject() = default;

            protected:
                SPtrJsonEntityMap _map;
                std::string _id;
                JsonValue _value;

            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONOBJECT_H
