//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_DERIVATIVE_H
#define CLDEPARSER_DERIVATIVE_H

#include "Token.h"

namespace CldeParser {

    class Derivative {

    public:
        Derivative() = default;
        Derivative(const Derivative &) = default;
        Derivative(Derivative &&) = default;
        Derivative &operator=(const Derivative &) = default;
        Derivative &operator=(Derivative &&) = default;
        virtual ~Derivative() = default;

        virtual bool Derive(const SPtrTokenVector &sptrTokenVector) = 0;
    };
}


#endif //CLDEPARSER_DERIVATIVE_H
