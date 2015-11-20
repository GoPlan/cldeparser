//
// Created by LE, Duc Anh on 8/23/15.
//

#ifndef CLDEPARSER_SCANNING_FORMATTER_TOKENIZERFORMATTER_H
#define CLDEPARSER_SCANNING_FORMATTER_TOKENIZERFORMATTER_H

#include <string>
#include <cldeparser/Commons.h>

namespace CLDEParser {
    namespace Scanning {
        namespace Formatter {
            struct TokenizerFormatter : public Common::IPrintFormatter {
                virtual std::string Print(const Common::IPrintable &printable) const;
            };
        }
    }
}


#endif //CLDEPARSER_SCANNING_FORMATTER_TOKENIZERFORMATTER_H
