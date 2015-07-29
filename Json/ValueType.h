//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_JSON_VALUETYPE_H
#define CLDEPARSER_JSON_VALUETYPE_H

namespace CldeParser {
    namespace Json {
        enum class ValueType {
            string,
            number,
            object,
            array,
            boolean,
            null
        };
    }
}

#endif //CLDEPARSER_JSON_VALUETYPE_H
