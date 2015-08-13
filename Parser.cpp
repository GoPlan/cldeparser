//
// Created by LE, Duc Anh on 8/5/15.
//

#include "Parser.h"
#include "Exceptions/Exception.h"

namespace CldeParser {

    SPtrSyntaxModelVector Parser::Parse(const SPtrTokenVector &sptrTokens) {

        SPtrDerivativeVector matchedDerivatives;
        SPtrSyntaxModelVector syntaxTrees;

        SPtrTokenVectorIterator startTokenIterator = sptrTokens.cbegin();
        SPtrTokenVectorIterator endingTokenIterator = sptrTokens.cend();

        while (startTokenIterator != endingTokenIterator && (*startTokenIterator) != nullptr) {

            for (auto &sptrDerivative : _derivatives) {
                sptrDerivative->Reset();
                if (sptrDerivative->IsFirst(*startTokenIterator))
                    matchedDerivatives.push_back(sptrDerivative);
            }

            if (matchedDerivatives.size() == 0) {
                std::string msg{"No derivative is matched"};
                throw Exceptions::Exception{msg};
            }

            syntaxTrees.push_back(ProcessAndMoveNext(startTokenIterator, endingTokenIterator,
                                                     matchedDerivatives));

            ++startTokenIterator;
        }

        return syntaxTrees;
    }

    SPtrSyntaxModel Parser::ProcessAndMoveNext(SPtrTokenVectorIterator &iterator,
                                              SPtrTokenVectorIterator &end,
                                              SPtrDerivativeVector &matchedDerivatives) {

        std::vector<SPtrDerivativeVector::const_iterator> unmatched;
        SPtrDerivativeVector::const_iterator last;

        while (iterator != end && (*iterator) != nullptr) {

            unmatched.clear();

            for (auto derivativeIter = matchedDerivatives.cbegin();
                 derivativeIter != matchedDerivatives.cend();
                 ++derivativeIter) {

                if (!(*derivativeIter)->Derive(iterator)) {
                    unmatched.push_back(derivativeIter);
                }
            }

            for (auto &item : unmatched) {
                matchedDerivatives.erase(item);
            }

            if (matchedDerivatives.size() > 0) {
                last = matchedDerivatives.cbegin();
            }

            ++iterator;
        }

        return (*last)->SyntaxTree();
    }
}


