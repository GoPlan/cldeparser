//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONVALUE_H
#define CLDEPARSER_PARSING_JSON_JSONVALUE_H

#include <string>
#include "JsonEntity.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {

            enum class JsonValueType {
                null = 0,
                string = 1,
                integer = 2,
                real = 3,
                boolean = 4,
                entity = 5
            };

            struct JsonValue {
                int id;
                int intValue;
                double doubleValue;
                bool boolValue;
                std::string strValue;
                SPtrJsonEntity sptrJsonEntity;
            };

            using SPtrJsonValue = std::shared_ptr<JsonValue>;
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONVALUE_H
