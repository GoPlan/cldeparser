//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONFACTORY_H
#define CLDEPARSER_PARSING_JSON_JSONFACTORY_H

#include "JsonEntity.h"
#include "JsonSyntaxNode.h"
#include "../../Derivative.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {
            struct JsonFactory {
                static SPtrDerivative CreateSPtrJsonDerivative();
                static SPtrJsonEntity CreateSPtrJsonObject();
                static SPtrJsonEntity CreateSPtrJsonArray();
                static SPtrJsonSyntaxNode CreateSPtrJsonSyntaxNode(int id, std::string const &value);
            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONFACTORY_H