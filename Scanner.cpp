//
// Created by LE, Duc Anh on 8/3/15.
//

#include "Scanner.h"
#include "Exceptions/ScannerException.h"
#include "Scanning/TokenType.h"
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
                tokenizer->Reset();
                if (tokenizer->BeginWithCharacter(*cIter)) { matchedTokenizers.push_back(tokenizer); }
            }

            if (matchedTokenizers.size() == 0) {
                std::string msg{"Unrecognized symbol - "};
                msg.append(1, *cIter);
                throw Exceptions::ScannerException{msg};
            }

            tokens.push_back(ProcessAndMoveNext(cIter, cEndr, matchedTokenizers));
        }

        return tokens;
    }

    SPtrToken Scanner::ProcessAndMoveNext(std::string::const_iterator &cIter,
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

            // Break if there is no tokenizer left
            if (matchedTokenizers.size() == 0) {
                break;
            }

            sptrToken = (*matchedTokenizers.cbegin())->CreateSPtrToken();

            ++cIter;
        }

        return sptrToken;
    }
}


