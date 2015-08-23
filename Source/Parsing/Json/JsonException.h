//
// Created by LE, Duc Anh on 8/13/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONEXCEPTION_H
#define CLDEPARSER_PARSING_JSON_JSONEXCEPTION_H

#include "../../Exceptions/Exception.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            class JsonException : Exceptions::Exception {

            public:
                JsonException(int code, std::string const &message) : Exception{code, message} { };
                JsonException(const JsonException &) = default;
                JsonException(JsonException &&) = default;
                JsonException &operator=(const JsonException &) = default;
                JsonException &operator=(JsonException &&) = default;
                virtual ~JsonException() = default;
            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONEXCEPTION_H
