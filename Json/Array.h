//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_JSON_ARRAY_H
#define CLDEPARSER_JSON_ARRAY_H

#include <vector>
#include "Object.h"

namespace CldeParser {
    namespace Json {

        using ObjectContainer = std::vector<Object>;

        class Array {

            ObjectContainer _container;

        public:
            Array() = default;
            Array(const Array &) = default;
            Array(Array &&) = default;
            Array &operator=(const Array &) = default;
            Array &operator=(Array &&) = default;
            virtual ~Array() = default;
        };
    }
}


#endif //CLDEPARSER_JSON_ARRAY_H
