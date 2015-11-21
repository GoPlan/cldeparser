//
// Created by LE, Duc Anh on 8/25/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONENTITYHELPER_H
#define CLDEPARSER_PARSING_JSON_JSONENTITYHELPER_H

#include "JsonEntity.h"
#include "JsonArray.h"
#include "JsonObject.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {
            struct JsonEntityHelper {
                static SPtrJsonArray ToSPtrArray(SPtrJsonEntity const &sptrJsonEntity);
                static SPtrJsonObject ToSPtrObject(SPtrJsonEntity const &sptrJsonEntity);
            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONENTITYHELPER_H
