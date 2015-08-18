//
// Created by LE, Duc Anh on 8/18/15.
//

#include "ParserSingle.h"

namespace CldeParser {

    SPtrSyntaxModel ParserSingle::Parse(const SPtrTokenVector &sptrTokens) {

        SPtrTokenVectorIterator cIter = sptrTokens.cbegin();

        if (!_sptrDerivative->Derive(cIter)) {
            //TODO: exception
        }

        return _sptrDerivative->SyntaxModel();
    }
}


