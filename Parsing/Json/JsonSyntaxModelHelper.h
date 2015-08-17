//
// Created by LE, Duc Anh on 8/17/15.
//

#ifndef CLDEPARSER_PARSING_JSON_HELPER_JSONSYNTAXMODELHELPER_H
#define CLDEPARSER_PARSING_JSON_HELPER_JSONSYNTAXMODELHELPER_H

#include "JsonSyntaxModel.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {
            struct JsonSyntaxModelHelper {
                static bool HasCurrentScope(SPtrJsonSyntaxModel const &sptrSyntaxModel);
                static SPtrJsonEntity &CurrentScopeEntity(SPtrJsonSyntaxModel const &sptrSyntaxModel);
            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_HELPER_JSONSYNTAXMODELHELPER_H
