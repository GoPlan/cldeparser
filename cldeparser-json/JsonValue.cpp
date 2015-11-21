//
// Created by LE, Duc Anh on 8/9/15.
//

#include "JsonEntity.h"
#include "JsonValue.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            std::string JsonValue::CopyToString() const {

                switch ((JsonValueType) id) {

                    case JsonValueType::Null:
                        return "null";

                    case JsonValueType::String:
                        return strValue;

                    case JsonValueType::Integer:
                        return std::to_string(intValue);

                    case JsonValueType::Real:
                        return std::to_string(doubleValue);

                    case JsonValueType::Boolean:
                        return std::to_string(boolValue);

                    case JsonValueType::Entity:
                        auto sptrIPrintable = std::dynamic_pointer_cast<Common::IPrintable>(sptrJsonEntity);
                        return sptrIPrintable->CopyToString();
                }
            }
        }
    }
}

