//
// Created by LE, Duc Anh on 8/9/15.
//

#include "Derivative.h"

namespace CldeParser {

    bool Derivative::Derive(SPtrTokenVectorIterator &sptrTokenIterator) {
        return CoreDerive(sptrTokenIterator);
    }

    SPtrSyntaxTree Derivative::SyntaxTree() {
        return _sptrSyntaxTree;
    }
    
    void Derivative::Reset() {
        // TODO: implementation
    }
}


