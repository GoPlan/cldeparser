//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_COMMON_IPRINTABLE_H
#define CLDEPARSER_COMMON_IPRINTABLE_H

#include <string>
#include "IPrintFormatter.h"

namespace CLDEParser {
    namespace Common {

        struct IPrintable {
            virtual std::string CopyToString() const = 0;
            virtual std::string CopyToString(IPrintFormatter const &formatter) const { return formatter.Print(*this); };
        };
    }
}

#endif //CLDEPARSER_COMMON_IPRINTABLE_H
