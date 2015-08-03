//
// Created by LE, Duc Anh on 8/3/15.
//

#include "SimpleScanner.h"
#include <iostream>

namespace CldeParser {

    SPtrTokenizerVector &SimpleScanner::Tokenizers() {
        return _tokenizers;
    }

    SPtrTokenVector SimpleScanner::Scan(const std::string &string) {

        SPtrTokenizerVector matchedTokenizers;
        SPtrTokenVector tokens;

        std::string::const_iterator cIter = string.cbegin();

        while (cIter != string.end()) {

            std::cout << (*cIter) << std::endl;

            matchedTokenizers.clear();

            for (auto &tokenizer: _tokenizers) {
                if (tokenizer->BeginWithCharacter(*cIter)) {
                    matchedTokenizers.push_back(tokenizer);
                }
            }

            tokens.push_back(Process(cIter, matchedTokenizers));

            ++cIter;
        }

        return tokens;
    }

    SPtrToken SimpleScanner::Process(const std::string::const_iterator &cIter,
                                     SPtrTokenizerVector &matchedTokenizers) {

        SPtrToken sptrToken;


        return sptrToken;
    }
}


