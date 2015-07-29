//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_JSON_OBJECT_H
#define CLDEPARSER_JSON_OBJECT_H

#include <unordered_map>
#include "Value.h"

namespace CldeParser {
    namespace Json {

        using PairValueMap = std::unordered_map<std::string, Value>;

        class Object {

            PairValueMap _mapPairValue;

        public:
            Object() = default;
            Object(const Object &) = default;
            Object(Object &&) = default;
            Object &operator=(const Object &) = default;
            Object &operator=(Object &&) = default;
            virtual ~Object() = default;


        };
    }
}


#endif //CLDEPARSER_JSON_OBJECT_H
