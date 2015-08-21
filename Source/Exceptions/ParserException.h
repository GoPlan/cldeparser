//
// Created by LE, Duc Anh on 8/5/15.
//

#ifndef CLDEPARSER_EXCEPTIONS_PARSEREXCEPTION_H
#define CLDEPARSER_EXCEPTIONS_PARSEREXCEPTION_H

#include "Exception.h"

namespace CldeParser {
    namespace Exceptions {

        class ParserException : public Exceptions::Exception {

            int _id;

        public:
            ParserException(int id, const std::string& message);
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
        };
    }
}


#endif //CLDEPARSER_EXCEPTIONS_PARSEREXCEPTION_H
