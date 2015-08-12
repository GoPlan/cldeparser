//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONDERIVATIVE_H
#define CLDEPARSER_PARSING_JSON_JSONDERIVATIVE_H

#include "../../Derivative.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {

            class JsonDerivative : public Derivative {

                SPtrTokenVector _matchedTokens;

                // Main
                bool json(const SPtrTokenVectorIterator &iterator);

                // NonTerminal matching
                void object_stmt(const SPtrTokenVectorIterator &iterator);
                void object(const SPtrTokenVectorIterator &iterator);
                void pair(const SPtrTokenVectorIterator &iterator);
                void pair_add(const SPtrTokenVectorIterator &iterator);
                void array_stmt(const SPtrTokenVectorIterator &iterator);
                void array(const SPtrTokenVectorIterator &iterator);
                void value(const SPtrTokenVectorIterator &iterator);
                void value_add(const SPtrTokenVectorIterator &iterator);

                // Terminal matching
                void matchId(const SPtrTokenVectorIterator &iterator);
                void matchColon(const SPtrTokenVectorIterator &iterator);
                void matchComma(const SPtrTokenVectorIterator &iterator);
                void matchBracketOpen(const SPtrTokenSetIterator &iterator);
                void matchBracketClosing(const SPtrTokenVectorIterator &iterator);
                void matchCurlyBraceOpen(const SPtrTokenVectorIterator &iterator);
                void matchCurlyBraceClosing(const SPtrTokenVectorIterator &iterator);


            public:
                JsonDerivative() = default;
                JsonDerivative(const JsonDerivative &) = default;
                JsonDerivative(JsonDerivative &&) = default;
                JsonDerivative &operator=(const JsonDerivative &) = default;
                JsonDerivative &operator=(JsonDerivative &&) = default;
                virtual ~JsonDerivative() = default;

                // Derivatives
                virtual bool Derive(const SPtrTokenVector &sptrTokenVector) override;
            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONDERIVATIVE_H
