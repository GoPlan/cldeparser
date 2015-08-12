//
// Created by LE, Duc Anh on 8/5/15.
//

#include "Parser.h"
#include "Exceptions/Exception.h"

namespace CldeParser {

    SPtrSyntaxTree Parser::Parse(const SPtrTokenVector &sptrTokens) {

        SPtrDerivativeVector matchedDerivatives;
        SPtrSyntaxTree sptrSyntaxTree;

        SPtrTokenVectorIterator tokenIter = sptrTokens.cbegin();
        SPtrTokenVectorIterator endingTokenIter = sptrTokens.cend();

        while (tokenIter != endingTokenIter) {

            for (auto &sptrDerivative : _derivatives) {
                sptrDerivative->Reset();
                if (sptrDerivative->IsFirst(*tokenIter))
                    matchedDerivatives.push_back(sptrDerivative);
            }

            if (matchedDerivatives.size() == 0) {
                std::string msg{"No derivative is matched"};
                throw Exceptions::Exception{msg};
            }

            ProcessAndMoveNext(tokenIter, endingTokenIter, matchedDerivatives);

            ++tokenIter;
        }

        return sptrSyntaxTree;
    }

    SPtrSyntaxTree Parser::ProcessAndMoveNext(SPtrTokenVectorIterator &iterator,
                                              SPtrTokenVectorIterator &end,
                                              const SPtrDerivativeVector &matchedDerivatives) {

        SPtrSyntaxTree sptrSyntaxTree;

        while (iterator != end) {

            for (auto &sptrDerivative : matchedDerivatives) {
                sptrDerivative->Derive(iterator);
            }

            ++iterator;
        }

        return sptrSyntaxTree;
    }
}


