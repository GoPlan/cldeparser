//
// Created by LE, Duc Anh on 8/24/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENFILTER_H
#define CLDEPARSER_SCANNING_TOKENFILTER_H

#include <vector>
#include "Token.h"

namespace CLDEParser {
    namespace Scanning {

        struct TokenHelper {
            static std::vector<int> DefaultFilterCodes();
            static SPtrTokenVector Filter(std::vector<int> const &filteredCodes, SPtrTokenVector const &tokens);
        };
    }
}


#endif //CLDEPARSER_SCANNING_TOKENFILTER_H
