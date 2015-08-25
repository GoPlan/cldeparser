//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_SCANNER_TOKENIZERFACTORY_H
#define CLDEPARSER_SCANNER_TOKENIZERFACTORY_H

#include "../Tokenizer.h"

namespace CLDEParser {
    namespace Scanning {
        class TokenizerFactory {
        public:
            static SPtrTokenizer CreateCurlyBraceOpen();
            static SPtrTokenizer CreateCurlyBraceClosing();
            static SPtrTokenizer CreateBracketOpen();
            static SPtrTokenizer CreateBracketClosing();
            static SPtrTokenizer CreateParenthesesOpen();
            static SPtrTokenizer CreateParenthesesClosing();
            static SPtrTokenizer CreateSquareBracketOpen();
            static SPtrTokenizer CreateSquareBracketClosing();
            static SPtrTokenizer CreateAngleBracketOpen();
            static SPtrTokenizer CreateAngleBracketClosing();
            static SPtrTokenizer CreateForwardSlash();
            static SPtrTokenizer CreateBackwardSlash();
            static SPtrTokenizer CreateColon();
            static SPtrTokenizer CreateSemiColon();
            static SPtrTokenizer CreateId();
            static SPtrTokenizer CreateNumber();
            static SPtrTokenizer CreateNumberInteger();
            static SPtrTokenizer CreateString();
            static SPtrTokenizer CreateSpace();
            static SPtrTokenizer CreateTab();
            static SPtrTokenizer CreateComma();
            static SPtrTokenizer CreateAdding();
            static SPtrTokenizer CreateSubtracting();
            static SPtrTokenizer CreateMultiplication();
            static SPtrTokenizer CreateDivision();
            static SPtrTokenizer CreateBoolFalse();
            static SPtrTokenizer CreateBoolTrue();
            static SPtrTokenizer CreateNull();
            static SPtrTokenizer CreateCarriageReturn();
            static SPtrTokenizer CreateLineFeed();
        };
    }
}


#endif //CLDEPARSER_COMMON_TOKENIZERFACTORY_H
