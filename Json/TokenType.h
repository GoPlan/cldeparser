//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_JSON_VALUETYPE_H
#define CLDEPARSER_JSON_VALUETYPE_H

namespace CldeParser {
    namespace Json {
        enum class TokenType {
            boolean = 1,
            string = 2,
            number = 3,
            object = 4,
            array = 5,
            null = 6
        };
    }
}

#endif //CLDEPARSER_JSON_VALUETYPE_H
