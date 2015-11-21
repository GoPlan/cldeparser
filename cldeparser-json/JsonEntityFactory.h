//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONENTITYFACTORY_H
#define CLDEPARSER_PARSING_JSON_JSONENTITYFACTORY_H

#include "JsonEntity.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {
            struct JsonEntityFactory {
                static UPtrJsonEntity CreateJsonObjectInstance();
                static UPtrJsonEntity CreateJsonArrayInstance();
            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONENTITYFACTORY_H
