//
// Created by LE, Duc Anh on 8/5/15.
//

#include "Exception.h"

namespace CLDEParser {
    namespace Exceptions {

        const char *Exception::what() const noexcept {
            return _message.c_str();
        }
    }
}


