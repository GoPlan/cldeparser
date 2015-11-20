//
// Created by LE, Duc Anh on 8/18/15.
//

#ifndef CLDEPARSER_PARSERSINGLE_H
#define CLDEPARSER_PARSERSINGLE_H

#include "SyntaxModel.h"
#include "Derivative.h"
#include "Exception.h"
#include <cldeparser/Commons.h>

namespace CLDEParser {

    class ParserSingle {

        SPtrDerivative _sptrDerivative;

    public:
        ParserSingle(SPtrDerivative const &sptrDerivative) : _sptrDerivative{sptrDerivative} { };
        ParserSingle(const ParserSingle &) = default;
        ParserSingle(ParserSingle &&) = default;
        ParserSingle &operator=(const ParserSingle &) = default;
        ParserSingle &operator=(ParserSingle &&) = default;
        virtual ~ParserSingle() = default;

        // Locals
        virtual SPtrSyntaxModel Parse(SPtrTokenVector const &sptrTokens) const;

        template<typename T>
        std::shared_ptr<T> ParseCast(SPtrTokenVector const &sptrTokens) const {
            return std::dynamic_pointer_cast<T>(Parse(sptrTokens));
        }
    };
}


#endif //CLDEPARSER_PARSERSINGLE_H
