//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONVALUE_H
#define CLDEPARSER_PARSING_JSON_JSONVALUE_H

#include <string>
#include "JsonEntity.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            enum class JsonValueType {
                Null = 0,
                String = 1,
                Integer = 2,
                Real = 3,
                Boolean = 4,
                Entity = 5
            };

            struct JsonValue : public Common::IPrintable {
                int id{0};
                int intValue{0};
                double doubleValue{0};
                bool boolValue{false};
                std::string strValue{};
                SPtrJsonEntity sptrJsonEntity{};

                // IPrintable
                std::string CopyToString() const override;

                // Locals
                JsonValueType Type() { return (JsonValueType) id; }
                bool IsNull() { return id == (int) JsonValueType::Null; }
            };

            using SPtrJsonValue = std::shared_ptr<JsonValue>;
            using SPtrJsonValueMap = std::unordered_map<std::string, SPtrJsonValue>;
            using SPtrJsonValueVector = std::vector<SPtrJsonValue>;
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONVALUE_H
