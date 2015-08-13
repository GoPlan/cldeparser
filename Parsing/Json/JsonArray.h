//
// Created by LE, Duc Anh on 8/10/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONARRAY_H
#define CLDEPARSER_PARSING_JSON_JSONARRAY_H

#include "JsonEntity.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {

            class JsonArray : public JsonEntity {

            public:
                JsonArray() = default;
                JsonArray(const JsonArray &) = default;
                JsonArray(JsonArray &&) = default;
                JsonArray &operator=(const JsonArray &) = default;
                JsonArray &operator=(JsonArray &&) = default;
                virtual ~JsonArray() = default;

                // Locals
                SPtrJsonEntityVector &Container() { return _children; }

            protected:
                SPtrJsonEntityVector _children;

            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONARRAY_H
