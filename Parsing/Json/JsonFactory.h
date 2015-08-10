//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONFACTORY_H
#define CLDEPARSER_PARSING_JSON_JSONFACTORY_H

#include "JsonEntity.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {
            struct JsonFactory {
                static JsonEntity CreateJsonObject();
                static JsonEntity CreateJsonArray();
            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONFACTORY_H
