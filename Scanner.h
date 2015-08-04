//
// Created by LE, Duc Anh on 8/3/15.
//

#ifndef CLDEPARSER_SCANNER_H
#define CLDEPARSER_SCANNER_H

#include "Token.h"
#include "Tokenizer.h"

namespace CldeParser {

    class Scanner {

        SPtrTokenizerVector _tokenizers;

    public:
        Scanner() = default;
        Scanner(const Scanner &) = default;
        Scanner(Scanner &&) = default;
        Scanner &operator=(const Scanner &) = default;
        Scanner &operator=(Scanner &&) = default;
        virtual ~Scanner() = default;

        // Locals
        SPtrTokenizerVector &Tokenizers();
        SPtrTokenVector Scan(const std::string &string);

    protected:
        SPtrToken ProcessAndMoveNext(std::string::const_iterator &cIter,
                                     std::string::const_iterator &cEnd,
                                     SPtrTokenizerList &matchedTokenizers);
    };
}


#endif //CLDEPARSER_SCANNER_H
