//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONENTITYFACTORY_H
#define CLDEPARSER_PARSING_JSON_JSONENTITYFACTORY_H

#include "JsonEntity.h"
#include "JsonSyntaxNode.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {
            struct JsonEntityFactory {
                static UPtrJsonEntity CreateJsonObjectInstance();
                static UPtrJsonEntity CreateJsonArrayInstance();
//                static UPtrJsonSyntaxNode CreateJsonSyntaxNodeInstance(int id, std::string const &value);
            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONENTITYFACTORY_H
