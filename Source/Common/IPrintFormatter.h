//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_COMMON_IPRINTFORMATTER_H
#define CLDEPARSER_COMMON_IPRINTFORMATTER_H

#include <string>

namespace CLDEParser {
    namespace Common {

        class IPrintable;

        struct IPrintFormatter {
            virtual std::string Print(const IPrintable &printable) const = 0;
        };
    }
}


#endif //CLDEPARSER_COMMON_IPRINTFORMATTER_H
