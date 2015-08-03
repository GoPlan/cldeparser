//
// Created by LE, Duc Anh on 8/3/15.
//

#ifndef CLDEPARSER_EXCEPTION_SCANNEREXCEPTION_H
#define CLDEPARSER_EXCEPTION_SCANNEREXCEPTION_H

#include <exception>
#include <string>

namespace CldeParser {

    class ScannerException : public std::exception {

        std::string _message;

    public:
        ScannerException(const std::string &message);
        ScannerException(const ScannerException &) = default;
        ScannerException(ScannerException &&) = default;
        ScannerException &operator=(const ScannerException &) = default;
        ScannerException &operator=(ScannerException &&) = default;
        virtual ~ScannerException() = default;

        // Exception
        virtual const char *what() const noexcept override;
    };
}


#endif //CLDEPARSER_EXCEPTION_SCANNEREXCEPTION_H
