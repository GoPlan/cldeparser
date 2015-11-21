//
// Created by LE, Duc Anh on 8/25/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONVALUEHELPER_H
#define CLDEPARSER_PARSING_JSON_JSONVALUEHELPER_H

#include "JsonValue.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            struct JsonValueHelper {

                static bool IsSupportedType(std::type_info const &typeInfo) {
                    if (typeInfo == typeid(int)) return true;
                    if (typeInfo == typeid(double)) return true;
                    if (typeInfo == typeid(bool)) return true;
                    if (typeInfo == typeid(std::string)) return true;
                    if (typeInfo == typeid(SPtrJsonEntity)) return true;
                    return false;
                }

                static bool ToBoolean(SPtrJsonValue const &sptrJsonValue);
                static int ToInteger(SPtrJsonValue const &sptrJsonValue);
                static double ToDouble(SPtrJsonValue const &sptrJsonValue);
                static std::string ToString(SPtrJsonValue const &sptrJsonValue);
                static SPtrJsonEntity ToSPtrJsonEntity(SPtrJsonValue const &sptrJsonValue);
            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONVALUEHELPER_H
