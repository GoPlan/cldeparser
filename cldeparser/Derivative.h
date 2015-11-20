//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_DERIVATIVE_H
#define CLDEPARSER_DERIVATIVE_H

#include "Token.h"
#include "SyntaxModel.h"

namespace CLDEParser {

    class Derivative {

    public:
        Derivative() = default;
        Derivative(const Derivative &) = default;
        Derivative(Derivative &&) = default;
        Derivative &operator=(const Derivative &) = default;
        Derivative &operator=(Derivative &&) = default;
        virtual ~Derivative() = default;

        // Locals
        virtual bool Derive(SPtrTokenVectorIterator &sptrTokenIterator);

        // Locals - Virtual
        virtual SPtrSyntaxModel SyntaxModel() = 0;
        virtual bool IsFirst(const SPtrToken &token) = 0;
        virtual void Reset() = 0;

    protected:
        virtual bool CoreDerive(SPtrTokenVectorIterator &sptrTokenIterator) = 0;

    };

    using UPtrDerivative = std::unique_ptr<Derivative>;
    using SPtrDerivative = std::shared_ptr<Derivative>;
    using SPtrDerivativeVector = std::vector<SPtrDerivative>;
}


#endif //CLDEPARSER_DERIVATIVE_H
