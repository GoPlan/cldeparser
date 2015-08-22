//
// Created by LE, Duc Anh on 8/3/15.
//

#ifndef CLDEPARSER_EXCEPTIONS_SCANNEREXCEPTION_H
#define CLDEPARSER_EXCEPTIONS_SCANNEREXCEPTION_H

#include <string>
#include "Exception.h"

namespace CldeParser {
    namespace Exceptions {

        class ScannerException : public Exception {

            int _id;

        public:
            ScannerException(int id, const std::string &message) : Exception{message}, _id{id} { }
            ScannerException(const ScannerException &) = default;
            ScannerException(ScannerException &&) = default;
            ScannerException &operator=(const ScannerException &) = default;
            ScannerException &operator=(ScannerException &&) = default;
            virtual ~ScannerException() = default;

            enum class ScannerExceptionCode {
                TokenUnmatchable,
                TokenizerUnsupportedFunction
            };
        };
    }
}


#endif //CLDEPARSER_EXCEPTIONS_SCANNEREXCEPTION_H
