//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_DERIVATIVE_H
#define CLDEPARSER_DERIVATIVE_H

#include "Token.h"
#include "SyntaxTree.h"

namespace CldeParser {

    class Derivative {

        SPtrSyntaxTree _sptrSyntaxTree;

    public:
        Derivative() = default;
        Derivative(const Derivative &) = default;
        Derivative(Derivative &&) = default;
        Derivative &operator=(const Derivative &) = default;
        Derivative &operator=(Derivative &&) = default;
        virtual ~Derivative() = default;

        // Locals
        bool Derive(SPtrTokenVectorIterator &sptrTokenIterator);
        void Reset();

        // Locals - Virtual
        virtual bool IsFirst(const SPtrToken &token) = 0;
        virtual SPtrSyntaxTree SyntaxTree();

    protected:
        virtual bool CoreDerive(SPtrTokenVectorIterator &sptrTokenIterator) = 0;

    };

    using SPtrDerivative = std::shared_ptr<Derivative>;
    using SPtrDerivativeVector = std::vector<SPtrDerivative>;
}


#endif //CLDEPARSER_DERIVATIVE_H
