//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_CORE_IPRINTFORMATTER_H
#define CLDEPARSER_CORE_IPRINTFORMATTER_H

#include <string>

namespace CldeParser {
    namespace Core {

        class IPrintable;

        struct IPrintFormatter {
            virtual std::string Print(const IPrintable &printable) const = 0;
        };
    }
}


#endif //CLDEPARSER_CORE_IPRINTFORMATTER_H
