//
// Created by LE, Duc Anh on 8/17/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_NUMBERREAL_H
#define CLDEPARSER_SCANNING_TOKENIZERS_NUMBERREAL_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            class NumberReal {

            public:
                NumberReal() = default;
                NumberReal(const NumberReal &) = default;
                NumberReal(NumberReal &&) = default;
                NumberReal &operator=(const NumberReal &) = default;
                NumberReal &operator=(NumberReal &&) = default;
                virtual ~NumberReal() = default;
            };
        }
    }
}


#endif //CLDEPARSER_SCANNING_TOKENIZERS_NUMBERREAL_H
