//
// Created by LE, Duc Anh on 8/3/15.
//

#include "Scanner.h"
#include <iostream>

namespace CldeParser {

    SPtrTokenizerVector &Scanner::Tokenizers() {
        return _tokenizers;
    }

    SPtrTokenVector Scanner::Scan(const std::string &string) {

        SPtrTokenizerList matchedTokenizers;
        SPtrTokenVector tokens;

        std::string::const_iterator cIter = string.cbegin();
        std::string::const_iterator cEndr = string.cend();

        while (cIter != string.end()) {

            matchedTokenizers.clear();

            for (auto &tokenizer: _tokenizers) {
                if (tokenizer->BeginWithCharacter(*cIter)) { matchedTokenizers.push_back(tokenizer); }
            }

            tokens.push_back(Process(cIter, cEndr, matchedTokenizers));

            ++cIter;
        }

        return tokens;
    }

    SPtrToken Scanner::Process(std::string::const_iterator &cIter,
                               std::string::const_iterator &cEnd,
                               SPtrTokenizerList &matchedTokenizers) {

        std::vector<SPtrTokenizerList::const_iterator> unmatched;

        SPtrToken sptrToken;

        while (cIter != cEnd) {

            unmatched.clear();

            // Validate character with tokenizers
            for (SPtrTokenizerList::const_iterator iter = matchedTokenizers.cbegin();
                 iter != matchedTokenizers.cend(); ++iter) {

                auto &tokenizer = *iter;

                if (!tokenizer->Validate(*cIter)) {
                    unmatched.push_back(iter);
                }
            }

            // Remove unmatched tokenizers
            for (auto &iter : unmatched) {
                matchedTokenizers.erase(iter);
            }

            // Update SPtrToken
            sptrToken = (*matchedTokenizers.cbegin())->CreateSPtrToken();

            // Break if there is no tokenizer left
            if (matchedTokenizers.size() == 0)
                break;

            ++cIter;
        }

        return sptrToken;
    }
}


