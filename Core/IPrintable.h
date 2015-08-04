//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_CORE_IPRINTABLE_H
#define CLDEPARSER_CORE_IPRINTABLE_H

#include <string>
#include "IPrintFormatter.h"

namespace CldeParser {
    namespace Core {

        struct IPrintable {
            virtual std::string CopyToString() const = 0;
            virtual std::string CopyToString(const IPrintFormatter &formatter) const { formatter.Print(*this); };
        };
    }
}

#endif //CLDEPARSER_CORE_IPRINTABLE_H
