//
// Created by LE, Duc Anh on 8/5/15.
//

#ifndef CLDEPARSER_PARSER_H
#define CLDEPARSER_PARSER_H

#include "SyntaxModel.h"
#include "Derivative.h"
#include "Exceptions/Exception.h"

namespace CLDEParser {

    class Parser {

        SPtrDerivativeVector _derivatives;

    public:
        Parser() = default;
        Parser(const Parser &) = default;
        Parser(Parser &&) = default;
        Parser &operator=(const Parser &) = default;
        Parser &operator=(Parser &&) = default;
        virtual ~Parser() = default;

        // Accessors & Mutators
        SPtrDerivativeVector &Derivatives() { return _derivatives; }

        // Locals
        virtual SPtrSyntaxModelVector Parse(const SPtrTokenVector &sptrTokens);

    protected:
        virtual SPtrSyntaxModel ProcessAndMoveNext(SPtrTokenVectorIterator &iterator,
                                                   SPtrTokenVectorIterator &end,
                                                   SPtrDerivativeVector &matchedDerivatives);

    };
}


#endif //CLDEPARSER_PARSER_H
