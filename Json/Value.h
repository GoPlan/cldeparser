//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_JSON_VALUE_H
#define CLDEPARSER_JSON_VALUE_H

#include "ValueType.h"

namespace CldeParser {
    namespace Json {

        class Value {

            ValueType _type;

        public:
            Value() = default;
            Value(const Value &) = default;
            Value(Value &&) = default;
            Value &operator=(const Value &) = default;
            Value &operator=(Value &&) = default;
            virtual ~Value() = default;
        };
    }
}


#endif //CLDEPARSER_JSON_VALUE_H
