//
// Created by LE, Duc Anh on 8/5/15.
//

#include "Exception.h"

namespace CldeParser {
    namespace Exceptions {

        Exception::Exception(const std::string &message) : _message{message} {
            //
        }

        const char *Exception::what() const noexcept {
            return _message.c_str();
        }
    }
}


