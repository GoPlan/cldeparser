//
// Created by LE, Duc Anh on 8/13/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONEXCEPTION_H
#define CLDEPARSER_PARSING_JSON_JSONEXCEPTION_H

#include "../../Exceptions/Exception.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {

            class JsonException : Exceptions::Exception {

            public:
                JsonException(std::string const &message) : Exception{message} { };
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
