//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_COMMON_TOKENIZERS_BRACKETOPEN_H
#define CLDEPARSER_COMMON_TOKENIZERS_BRACKETOPEN_H

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            class BracketOpen {

            public:
                BracketOpen() = default;
                BracketOpen(const BracketOpen &) = default;
                BracketOpen(BracketOpen &&) = default;
                BracketOpen &operator=(const BracketOpen &) = default;
                BracketOpen &operator=(BracketOpen &&) = default;
                virtual ~BracketOpen() = default;
            };
        }
    }
}


#endif //CLDEPARSER_COMMON_TOKENIZERS_BRACKETOPEN_H
