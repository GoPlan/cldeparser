//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_COMMON_IPRINTABLE_H
#define CLDEPARSER_COMMON_IPRINTABLE_H

#include <string>
#include "IPrintFormatter.h"

namespace CldeParser {
    namespace Common {

        struct IPrintable {
            virtual std::string CopyToString() = 0;
            virtual std::string CopyToString(const IPrintFormatter &formatter) { formatter.Print(*this); };
        };
    }
}

#endif //CLDEPARSER_IPRINTABLE_H
