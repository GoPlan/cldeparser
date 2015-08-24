//
// Created by LE, Duc Anh on 8/5/15.
//

#ifndef CLDEPARSER_EXCEPTIONS_PARSEREXCEPTION_H
#define CLDEPARSER_EXCEPTIONS_PARSEREXCEPTION_H

#include "Exception.h"
#include "../Token.h"

namespace CLDEParser {
    namespace Exceptions {

        class ParserException : public Exception {

            int _code;
            SPtrTokenVectorIterator _iterator;
            std::string _description;

        public:
            ParserException(int code, SPtrTokenVectorIterator const &iterator, std::string const &description);
            ParserException(int code, SPtrTokenVectorIterator const &iterator);
            ParserException(const ParserException &) = default;
            ParserException(ParserException &&) = default;
            ParserException &operator=(const ParserException &) = default;
            ParserException &operator=(ParserException &&) = default;
            virtual ~ParserException() = default;

            enum class ParserExceptionCode {
                UnmatchedToken = 0,
                UnknownEntityType = 1,
                UnknownValueType = 2
            };

            // Locals
            SPtrTokenVectorIterator const &Iterator() const { return _iterator; }
            ParserExceptionCode Code() const { return (ParserExceptionCode) _code; }

            static std::string CopyToString(ParserExceptionCode code);
        };
    }
}


#endif //CLDEPARSER_EXCEPTIONS_PARSEREXCEPTION_H
