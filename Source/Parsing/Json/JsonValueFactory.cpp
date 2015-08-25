//
// Created by LE, Duc Anh on 8/17/15.
//

#include "JsonValueFactory.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            SPtrJsonValue JsonValueFactory::CreateInteger(std::string const &value) {
                SPtrJsonValue sptrValue = std::make_shared<JsonValue>();
                sptrValue->id = (int) JsonValueType::Integer;
                sptrValue->intValue = std::stoi(value);
                return sptrValue;
            }

            SPtrJsonValue JsonValueFactory::CreateDouble(std::string const &value) {
                SPtrJsonValue sptrValue = std::make_shared<JsonValue>();
                sptrValue->id = (int) JsonValueType::Real;
                sptrValue->doubleValue = std::stod(value);
                return sptrValue;
            }

            SPtrJsonValue JsonValueFactory::CreateString(std::string const &value) {
                SPtrJsonValue sptrValue = std::make_shared<JsonValue>();
                sptrValue->id = (int) JsonValueType::String;
                sptrValue->strValue = value;
                return sptrValue;
            }

            SPtrJsonValue JsonValueFactory::CreateBooleanTrue() {
                SPtrJsonValue sptrValue = std::make_shared<JsonValue>();
                sptrValue->id = (int) JsonValueType::Boolean;
                sptrValue->boolValue = true;
                return sptrValue;
            }

            SPtrJsonValue JsonValueFactory::CreateBooleanFalse() {
                SPtrJsonValue sptrValue = std::make_shared<JsonValue>();
                sptrValue->id = (int) JsonValueType::Boolean;
                sptrValue->boolValue = false;
                return sptrValue;
            }

            SPtrJsonValue JsonValueFactory::CreateNull() {
                SPtrJsonValue sptrValue = std::make_shared<JsonValue>();
                sptrValue->id = (int) JsonValueType::Null;
                return sptrValue;
            }

            SPtrJsonValue JsonValueFactory::CreateEntityValue(SPtrJsonEntity const &sptrJsonEntity) {
                SPtrJsonValue sptrValue = std::make_shared<JsonValue>();
                sptrValue->id = (int) JsonValueType::Entity;
                sptrValue->sptrJsonEntity = sptrJsonEntity;
                return sptrValue;
            }
        }
    }
}


