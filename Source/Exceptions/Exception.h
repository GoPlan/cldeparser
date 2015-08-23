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
            Exception(int code, const std::string &message);
            Exception(const Exception &) = default;
            Exception(Exception &&) = default;
            Exception &operator=(const Exception &) = default;
            Exception &operator=(Exception &&) = default;
            virtual ~Exception() = default;

            // Exceptions
            virtual const char *what() const noexcept override;

        protected:
            int _code;
            std::string _message;
            std::string _description;

        };
    }
}


#endif //CLDEPARSER_EXCEPTIONS_EXCEPTION_H
