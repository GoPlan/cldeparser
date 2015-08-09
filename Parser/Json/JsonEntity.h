//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSER_JSONENTITY_H
#define CLDEPARSER_PARSER_JSONENTITY_H

namespace CldeParser {
    namespace Parser {

        enum class JsonEntityType {
            Unknown = 0,
            Object = 1,
            Array = 2
        };

        class JsonEntity {

        public:
            JsonEntity() = default;
            JsonEntity(const JsonEntity &) = default;
            JsonEntity(JsonEntity &&) = default;
            JsonEntity &operator=(const JsonEntity &) = default;
            JsonEntity &operator=(JsonEntity &&) = default;
            virtual ~JsonEntity() = default;

        protected:
            JsonEntityType _type{JsonEntityType::Unknown};
        };
    }
}


#endif //CLDEPARSER_PARSER_JSONENTITY_H
