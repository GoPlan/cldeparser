//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_COMMON_TOKENIZERFACTORY_H
#define CLDEPARSER_COMMON_TOKENIZERFACTORY_H

#include "../Tokenizer.h"

namespace CldeParser {
    namespace Common {

        class TokenizerFactory {
        public:
            static SPtrTokenizer CreateBraceOpen();
            static SPtrTokenizer CreateBraceClose();
            static SPtrTokenizer CreateColon();
            static SPtrTokenizer CreateId();
            static SPtrTokenizer CreateNumber();
            static SPtrTokenizer CreateString();
            static SPtrTokenizer CreateSpace();
            static SPtrTokenizer CreateTab();
            static SPtrTokenizer CreateComma();
        };
    }
}


#endif //CLDEPARSER_COMMON_TOKENIZERFACTORY_H
