//
// Created by LE, Duc Anh on 8/3/15.
//

#ifndef CLDEPARSER_SIMPLESCANNER_H
#define CLDEPARSER_SIMPLESCANNER_H

#include "Token.h"
#include "Tokenizer.h"

namespace CldeParser {

    class SimpleScanner {

        SPtrTokenizerVector _tokenizers;

    public:
        SimpleScanner() = default;
        SimpleScanner(const SimpleScanner &) = default;
        SimpleScanner(SimpleScanner &&) = default;
        SimpleScanner &operator=(const SimpleScanner &) = default;
        SimpleScanner &operator=(SimpleScanner &&) = default;
        virtual ~SimpleScanner() = default;

        // Locals
        SPtrTokenizerVector &Tokenizers();
        SPtrTokenVector Scan(const std::string &string);

    protected:
        SPtrToken Process(const std::string::const_iterator &cIter, SPtrTokenizerVector &matchedTokenizers);
    };
}


#endif //CLDEPARSER_SIMPLESCANNER_H
