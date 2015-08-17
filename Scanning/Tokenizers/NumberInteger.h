//
// Created by LE, Duc Anh on 8/17/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_NUMBERINTEGER_H
#define CLDEPARSER_SCANNING_TOKENIZERS_NUMBERINTEGER_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            class NumberInteger {
            
            public:
                NumberInteger() = default;
                NumberInteger(const NumberInteger &) = default;
                NumberInteger(NumberInteger &&) = default;
                NumberInteger &operator=(const NumberInteger &) = default;
                NumberInteger &operator=(NumberInteger &&) = default;
                virtual ~NumberInteger() = default;
            };
        }
    }
}

#endif //CLDEPARSER_SCANNING_TOKENIZERS_NUMBERINTEGER_H
