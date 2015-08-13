//
// Created by LE, Duc Anh on 8/5/15.
//

#ifndef CLDEPARSER_PARSER_H
#define CLDEPARSER_PARSER_H

#include "SyntaxTree.h"
#include "Derivative.h"

namespace CldeParser {

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
        virtual SPtrSyntaxTreeVector Parse(const SPtrTokenVector &sptrTokens);

    protected:
        virtual SPtrSyntaxTree ProcessAndMoveNext(SPtrTokenVectorIterator &iterator,
                                                  SPtrTokenVectorIterator &end,
                                                  SPtrDerivativeVector &matchedDerivatives);

    };
}


#endif //CLDEPARSER_PARSER_H
