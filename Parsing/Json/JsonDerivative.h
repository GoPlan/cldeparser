//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONDERIVATIVE_H
#define CLDEPARSER_PARSING_JSON_JSONDERIVATIVE_H

#include "../../Derivative.h"

namespace CldeParser {
    namespace Parser {
        namespace Json {

            class JsonDerivative : public Derivative {

                SPtrTokenVector _matchedTokens;

                bool main(const SPtrToken &token);

                // NonTerminal matching
                bool matchObject(const SPtrToken &token);
                bool matchArray(const SPtrToken &token);

                // Terminal matching
                bool matchOpenBracket(const SPtrToken &token);
                bool matchClosingBracket(const SPtrToken &token);
                bool matchOpenBrace(const SPtrToken &token);
                bool matchClosingBrace(const SPtrToken &token);
                bool matchComma(const SPtrToken &token);
                bool matchColon(const SPtrToken &token);
                bool matchId(const SPtrToken &token);
                bool matchValue(const SPtrToken &token);

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
