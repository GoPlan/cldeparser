//
// Created by LE, Duc Anh on 8/3/15.
//

#ifndef CLDEPARSER_EXCEPTIONS_SCANNEREXCEPTION_H
#define CLDEPARSER_EXCEPTIONS_SCANNEREXCEPTION_H

#include <string>
#include "Exception.h"

namespace CLDEParser {
    namespace Exceptions {

        class ScannerException : public Exception {

            char _token;

        public:
            ScannerException(int code, std::string const &description);
            ScannerException(char token, int code, std::string const &description);
            ScannerException(const ScannerException &) = default;
            ScannerException(ScannerException &&) = default;
            ScannerException &operator=(const ScannerException &) = default;
            ScannerException &operator=(ScannerException &&) = default;
            virtual ~ScannerException() = default;

            enum class ScannerExceptionCode {
                TokenUnmatchable = 0,
                TokenizerUnsupportedFunction = 1
            };

            static std::string CopyToString(ScannerExceptionCode code);
        };
    }
}


#endif //CLDEPARSER_EXCEPTIONS_SCANNEREXCEPTION_H
