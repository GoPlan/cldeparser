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
                bool json(SPtrTokenVectorIterator &iterator);

                // Terminal matching
                void matchId(SPtrTokenVectorIterator &iterator);
                void matchColon(SPtrTokenVectorIterator &iterator);
                void matchComma(SPtrTokenVectorIterator &iterator);
                void matchBracketOpen(SPtrTokenVectorIterator &iterator);
                void matchBracketClosing(SPtrTokenVectorIterator &iterator);
                void matchCurlyBraceOpen(SPtrTokenVectorIterator &iterator);
                void matchCurlyBraceClosing(SPtrTokenVectorIterator &iterator);
                void matchString(SPtrTokenVectorIterator &iterator);
                void matchNumber(SPtrTokenVectorIterator &iterator);
                void matchTrue(SPtrTokenVectorIterator &iterator);
                void matchFalse(SPtrTokenVectorIterator &iterator);
                void matchNull(SPtrTokenVectorIterator &iterator);

                // NonTerminal matching
                void object_stmt(SPtrTokenVectorIterator &iterator);
                void object(SPtrTokenVectorIterator &iterator);
                void pair(SPtrTokenVectorIterator &iterator);
                void name(SPtrTokenVectorIterator &iterator);
                void pair_add(SPtrTokenVectorIterator &iterator);
                void array_stmt(SPtrTokenVectorIterator &iterator);
                void array(SPtrTokenVectorIterator &iterator);
                void value(SPtrTokenVectorIterator &iterator);
                void value_add(SPtrTokenVectorIterator &iterator);

            public:
                JsonDerivative() = default;
                JsonDerivative(const JsonDerivative &) = default;
                JsonDerivative(JsonDerivative &&) = default;
                JsonDerivative &operator=(const JsonDerivative &) = default;
                JsonDerivative &operator=(JsonDerivative &&) = default;
                virtual ~JsonDerivative() = default;

                // Derivatives
                virtual bool IsFirst(const SPtrToken &token) override;

            protected:
                // Derivatives
                virtual bool CoreDerive(SPtrTokenVectorIterator &sptrTokenIterator) override;
            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONDERIVATIVE_H
