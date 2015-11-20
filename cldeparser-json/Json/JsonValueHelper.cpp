//
// Created by LE, Duc Anh on 8/25/15.
//

#include "JsonValueHelper.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            int JsonValueHelper::ToInteger(SPtrJsonValue const &sptrJsonValue) {
                return sptrJsonValue->intValue;
            }

            double JsonValueHelper::ToDouble(SPtrJsonValue const &sptrJsonValue) {
                return sptrJsonValue->doubleValue;
            }

            bool JsonValueHelper::ToBoolean(SPtrJsonValue const &sptrJsonValue) {
                return sptrJsonValue->boolValue;
            }

            std::string JsonValueHelper::ToString(SPtrJsonValue const &sptrJsonValue) {
                return sptrJsonValue->strValue;
            }

            SPtrJsonEntity JsonValueHelper::ToSPtrJsonEntity(SPtrJsonValue const &sptrJsonValue) {
                return sptrJsonValue->sptrJsonEntity;
            }
        }
    }
}