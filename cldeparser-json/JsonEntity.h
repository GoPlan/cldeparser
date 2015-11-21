//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONENTITY_H
#define CLDEPARSER_PARSING_JSON_JSONENTITY_H

#include <cldeparser/Commons.h>
#include <memory>
#include <unordered_map>
#include <vector>
#include "JsonValue.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            enum class JsonEntityType {
                Unknown = 0,
                Object = 1,
                Array = 2
            };

            class JsonEntity : public Common::IPrintable {

            public:
                JsonEntity() = default;
                virtual ~JsonEntity() = default;

                // Accessors & Mutators
                JsonEntityType const &Type() const { return _type; }

                // Locals
                virtual SPtrJsonValueVector &Container() = 0;
                virtual SPtrJsonValue GetValue(std::string const &id) = 0;
                virtual void SetValue(std::string const &id, SPtrJsonValue const &value) = 0;

            protected:
                JsonEntity(JsonEntityType type) : _type{type} { };
                JsonEntityType _type{JsonEntityType::Unknown};

            };

            using UPtrJsonEntity = std::unique_ptr<JsonEntity>;
            using SPtrJsonEntity = std::shared_ptr<JsonEntity>;
            using SPtrJsonEntityMap = std::unordered_map<std::string, SPtrJsonEntity>;
            using SPtrJsonEntityVector = std::vector<SPtrJsonEntity>;
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONENTITY_H
