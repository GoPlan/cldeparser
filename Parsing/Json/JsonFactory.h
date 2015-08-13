//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONFACTORY_H
#define CLDEPARSER_PARSING_JSON_JSONFACTORY_H

#include "JsonEntity.h"
#include "../../SyntaxModel.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {
            struct JsonFactory {
                static JsonEntity Create(SPtrSyntaxModel const &sptrSyntaxModel);
            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONFACTORY_H
