//
// Created by LE, Duc Anh on 8/13/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONEXCEPTION_H
#define CLDEPARSER_PARSING_JSON_JSONEXCEPTION_H

#include "../../Exceptions/Exception.h"
#include "JsonSyntaxNode.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            class JsonException : Exceptions::Exception {

                int _code;
                SPtrJsonSyntaxNodeIterator _iterator;
                std::string _description;

            public:
                JsonException(int code, std::string const &description);
                JsonException(int code, SPtrJsonSyntaxNodeIterator const &iterator);
                JsonException(const JsonException &) = default;
                JsonException(JsonException &&) = default;
                JsonException &operator=(const JsonException &) = default;
                JsonException &operator=(JsonException &&) = default;
                virtual ~JsonException() = default;

                enum class JsonExceptionCode {
                    UnknownSyntaxNode,
                    UnknownValueType,
                    InvalidTypeCasting,
                    UnSupportedValueType,
                    ValueIsNull
                };

                static std::string CopyToString(JsonExceptionCode code);
            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONEXCEPTION_H
