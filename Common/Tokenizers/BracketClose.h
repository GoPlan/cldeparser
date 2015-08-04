//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_COMMON_TOKENIZERS_BRACKETCLOSE_H
#define CLDEPARSER_COMMON_TOKENIZERS_BRACKETCLOSE_H

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            class BracketClose {

            public:
                BracketClose() = default;
                BracketClose(const BracketClose &) = default;
                BracketClose(BracketClose &&) = default;
                BracketClose &operator=(const BracketClose &) = default;
                BracketClose &operator=(BracketClose &&) = default;
                virtual ~BracketClose() = default;
            };
        }
    }
}


#endif //CLDEPARSER_COMMON_TOKENIZERS_BRACKETCLOSE_H
