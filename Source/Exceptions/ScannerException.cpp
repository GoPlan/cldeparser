//
// Created by LE, Duc Anh on 8/3/15.
//

#include "ScannerException.h"

namespace CldeParser {
    namespace Exceptions {

        ScannerException::ScannerException(const std::string &message) : _message{message} {
            //
        }

        const char *ScannerException::what() const noexcept {
            return _message.c_str();
        }
    }
}


