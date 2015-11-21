//
// Created by LE, Duc Anh on 8/25/15.
//

#include "JsonEntityHelper.h"
#include "JsonException.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            SPtrJsonArray JsonEntityHelper::ToSPtrArray(SPtrJsonEntity const &sptrJsonEntity) {

                if (sptrJsonEntity->Type() != JsonEntityType::Array) {
                    int code = (int) JsonException::JsonExceptionCode::InvalidTypeCasting;
                    throw JsonException{code, std::string{}};
                }

                return std::dynamic_pointer_cast<JsonArray>(sptrJsonEntity);
            }

            SPtrJsonObject JsonEntityHelper::ToSPtrObject(SPtrJsonEntity const &sptrJsonEntity) {

                if (sptrJsonEntity->Type() != JsonEntityType::Object) {
                    int code = (int) JsonException::JsonExceptionCode::InvalidTypeCasting;
                    throw JsonException{code, std::string{}};
                }

                return std::dynamic_pointer_cast<JsonObject>(sptrJsonEntity);
            }
        }
    }
}
