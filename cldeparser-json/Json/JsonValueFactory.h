//
// Created by LE, Duc Anh on 8/17/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONVALUEFACTORY_H
#define CLDEPARSER_PARSING_JSON_JSONVALUEFACTORY_H

#include "JsonValue.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            struct JsonValueFactory {
                static SPtrJsonValue CreateNull();
                static SPtrJsonValue CreateBooleanTrue();
                static SPtrJsonValue CreateBooleanFalse();
                static SPtrJsonValue CreateInteger(std::string const &value);
                static SPtrJsonValue CreateDouble(std::string const &value);
                static SPtrJsonValue CreateString(std::string const &value);
                static SPtrJsonValue CreateEntityValue(SPtrJsonEntity const &sptrJsonEntity);
            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONVALUEFACTORY_H
