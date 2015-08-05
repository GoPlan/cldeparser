//
// Created by LE, Duc Anh on 8/5/15.
//

#ifndef CLDEPARSER_EXCEPTIONS_EXCEPTION_H
#define CLDEPARSER_EXCEPTIONS_EXCEPTION_H

#include <string>
#include <exception>

namespace CldeParser {
    namespace Exceptions {

        class Exception : public std::exception {

            std::string _message;

        public:
            Exception(const std::string &message);
            Exception(const Exception &) = default;
            Exception(Exception &&) = default;
            Exception &operator=(const Exception &) = default;
            Exception &operator=(Exception &&) = default;
            virtual ~Exception() = default;

            // Exceptions
            virtual const char *what() const noexcept override;
        };
    }
}


#endif //CLDEPARSER_EXCEPTIONS_EXCEPTION_H
