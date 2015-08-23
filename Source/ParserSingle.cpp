//
// Created by LE, Duc Anh on 8/18/15.
//

#include "ParserSingle.h"
#include "Exceptions/ParserException.h"

namespace CLDEParser {

    SPtrSyntaxModel ParserSingle::Parse(const SPtrTokenVector &sptrTokens) {

        auto cIter = sptrTokens.cbegin();

        if (!_sptrDerivative->Derive(cIter)) {
            int code = (int) Exceptions::ParserException::ParserExceptionCode::UnmatchedToken;
            std::string msg{"Derivative can not match " + (*cIter)->CopyToString()};
            throw Exceptions::ParserException{code, msg};
        }

        return _sptrDerivative->SyntaxModel();
    }
}


