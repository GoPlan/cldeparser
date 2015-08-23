//
// Created by LE, Duc Anh on 8/9/15.
//

#include "JsonValue.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            std::string JsonValue::CopyToString() const {

                switch ((JsonValueType) id) {

                    case JsonValueType::null:
                        return "null";

                    case JsonValueType::string:
                        return strValue;

                    case JsonValueType::integer:
                        return std::to_string(intValue);

                    case JsonValueType::real:
                        return std::to_string(doubleValue);

                    case JsonValueType::boolean:
                        return std::to_string(boolValue);

                    case JsonValueType::entity:
                        return sptrJsonEntity->CopyToString();
                }
            }
        }
    }
}

