//
// Created by LE, Duc Anh on 8/5/15.
//

#ifndef CLDEPARSER_EXCEPTIONS_PARSEREXCEPTION_H
#define CLDEPARSER_EXCEPTIONS_PARSEREXCEPTION_H

#include "Exception.h"

namespace CLDEParser {
    namespace Exceptions {

        class ParserException : public Exception {

        public:
            ParserException(int code, const std::string &description);
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

            static std::string CopyToString(ParserExceptionCode code);
        };
    }
}


#endif //CLDEPARSER_EXCEPTIONS_PARSEREXCEPTION_H
