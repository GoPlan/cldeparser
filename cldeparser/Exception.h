//
// Created by LE, Duc Anh on 8/5/15.
//

#ifndef CLDEPARSER_EXCEPTIONS_EXCEPTION_H
#define CLDEPARSER_EXCEPTIONS_EXCEPTION_H

#include <string>
#include <exception>

namespace CLDEParser {
    namespace Exceptions {

        class Exception : public std::exception {

        public:
            Exception() = default;
            Exception(const Exception &) = default;
            Exception(Exception &&) = default;
            Exception &operator=(const Exception &) = default;
            Exception &operator=(Exception &&) = default;
            virtual ~Exception();

            // Exceptions
            virtual const char *what() const noexcept override;

        protected:
            std::string _message;

        };
    }
}


#endif //CLDEPARSER_EXCEPTIONS_EXCEPTION_H
