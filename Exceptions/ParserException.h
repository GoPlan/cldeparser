//
// Created by LE, Duc Anh on 8/5/15.
//

#ifndef CLDEPARSER_EXCEPTIONS_PARSEREXCEPTION_H
#define CLDEPARSER_EXCEPTIONS_PARSEREXCEPTION_H

#include <exception>

namespace CldeParser {
    namespace Exceptions {

        class ParserException : std::exception {

        public:
            ParserException() = default;
            ParserException(const ParserException &) = default;
            ParserException(ParserException &&) = default;
            ParserException &operator=(const ParserException &) = default;
            ParserException &operator=(ParserException &&) = default;
            virtual ~ParserException() = default;
        };
    }
}


#endif //CLDEPARSER_EXCEPTIONS_PARSEREXCEPTION_H
