//
// Created by LE, Duc Anh on 8/3/15.
//

#include "Scanner.h"

namespace CLDEParser {

    SPtrTokenizerVector &Scanner::Tokenizers() {
        return _tokenizers;
    }

    SPtrTokenVector Scanner::Scan(const std::string &string) const {

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

                std::string desc;
                desc.reserve(Common::BufferSize::EIGHTY);

                auto cTokenEnd = tokens.cend();
                auto cTokenIter = tokens.cbegin();

                if (tokens.size() > _exceptionTokenNo) {
                    cTokenIter = cTokenIter + (tokens.size() - _exceptionTokenNo);
                }

                for (; cTokenIter != cTokenEnd; ++cTokenIter) {
                    desc += (*cTokenIter)->CopyToString();
                }

                desc += *cIter;

                throw Exceptions::ScannerException{
                        (int) Exceptions::ScannerException::ScannerExceptionCode::TokenUnmatchable, desc, (*cIter)};
            }

            tokens.push_back(ProcessAndMoveNext(cIter, cEndr, matchedTokenizers));
        }

        return tokens;
    }

    SPtrToken Scanner::ProcessAndMoveNext(std::string::const_iterator &cIter,
                                          std::string::const_iterator &cEnd,
                                          SPtrTokenizerList &matchedTokenizers) const {

        std::vector<SPtrTokenizerList::const_iterator> unmatched;
        SPtrTokenizer sptrTokenizer;

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

            sptrTokenizer = *(matchedTokenizers.cbegin());

            ++cIter;
        }

        return sptrTokenizer->CreateSPtrToken();
    }
}