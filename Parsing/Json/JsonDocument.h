//
// Created by LE, Duc Anh on 8/10/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONDOCUMENT_H
#define CLDEPARSER_PARSING_JSON_JSONDOCUMENT_H

#include "JsonEntity.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {

            class JsonDocument {

            public:
                JsonDocument() = default;
                JsonDocument(const JsonDocument &) = default;
                JsonDocument(JsonDocument &&) = default;
                JsonDocument &operator=(const JsonDocument &) = default;
                JsonDocument &operator=(JsonDocument &&) = default;
                virtual ~JsonDocument() = default;

            protected:
                SPtrJsonEntity _sptrRootEntity;

            };
        }
    }
}


#endif //CLDEPARSER_JSONDOCUMENT_H
