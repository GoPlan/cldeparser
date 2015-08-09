//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSER_JSONVALUE_H
#define CLDEPARSER_PARSER_JSONVALUE_H

#include "JsonEntity.h"

namespace CldeParser {
    namespace Parser {

        class JsonValue {

        public:
            JsonValue() = default;
            JsonValue(const JsonValue &) = default;
            JsonValue(JsonValue &&) = default;
            JsonValue &operator=(const JsonValue &) = default;
            JsonValue &operator=(JsonValue &&) = default;
            virtual ~JsonValue() = default;
        };
    }
}


#endif //CLDEPARSER_PARSER_JSONVALUE_H
