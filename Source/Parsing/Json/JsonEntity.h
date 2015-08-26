//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONENTITY_H
#define CLDEPARSER_PARSING_JSON_JSONENTITY_H

#include <memory>
#include <unordered_map>
#include <vector>
#include "../../Common/IPrintable.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            enum class JsonEntityType {
                Unknown = 0,
                Object = 1,
                Array = 2
            };

            class JsonEntity;

            using UPtrJsonEntity = std::unique_ptr<JsonEntity>;
            using SPtrJsonEntity = std::shared_ptr<JsonEntity>;
            using SPtrJsonEntityMap = std::unordered_map<std::string, SPtrJsonEntity>;
            using SPtrJsonEntityVector = std::vector<SPtrJsonEntity>;

            class JsonEntity : public Common::IPrintable,
                               public std::enable_shared_from_this<JsonEntity> {

            public:
                JsonEntity() = default;
                JsonEntity(const JsonEntity &) = default;
                JsonEntity(JsonEntity &&) = default;
                JsonEntity &operator=(const JsonEntity &) = default;
                JsonEntity &operator=(JsonEntity &&) = default;
                virtual ~JsonEntity() = default;

                // Accessors & Mutators
                JsonEntityType const &Type() const { return _type; }

            protected:
                JsonEntity(JsonEntityType type) : _type{type} { };
                JsonEntityType _type{JsonEntityType::Unknown};

            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONENTITY_H
