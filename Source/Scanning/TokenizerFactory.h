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
            static UPtrTokenizer CreateCurlyBraceOpen();
            static UPtrTokenizer CreateCurlyBraceClosing();
            static UPtrTokenizer CreateBracketOpen();
            static UPtrTokenizer CreateBracketClosing();
            static UPtrTokenizer CreateParenthesesOpen();
            static UPtrTokenizer CreateParenthesesClosing();
            static UPtrTokenizer CreateSquareBracketOpen();
            static UPtrTokenizer CreateSquareBracketClosing();
            static UPtrTokenizer CreateAngleBracketOpen();
            static UPtrTokenizer CreateAngleBracketClosing();
            static UPtrTokenizer CreateForwardSlash();
            static UPtrTokenizer CreateBackwardSlash();
            static UPtrTokenizer CreateColon();
            static UPtrTokenizer CreateSemiColon();
            static UPtrTokenizer CreateId();
            static UPtrTokenizer CreateNumber();
            static UPtrTokenizer CreateNumberInteger();
            static UPtrTokenizer CreateString();
            static UPtrTokenizer CreateSpace();
            static UPtrTokenizer CreateTab();
            static UPtrTokenizer CreateComma();
            static UPtrTokenizer CreateAdding();
            static UPtrTokenizer CreateSubtracting();
            static UPtrTokenizer CreateMultiplication();
            static UPtrTokenizer CreateDivision();
            static UPtrTokenizer CreateBoolFalse();
            static UPtrTokenizer CreateBoolTrue();
            static UPtrTokenizer CreateNull();
            static UPtrTokenizer CreateCarriageReturn();
            static UPtrTokenizer CreateLineFeed();
        };
    }
}


#endif //CLDEPARSER_COMMON_TOKENIZERFACTORY_H
