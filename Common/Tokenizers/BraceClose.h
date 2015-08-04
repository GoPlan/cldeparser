//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_COMMON_TOKENIZERS_BRACECLOSE_H
#define CLDEPARSER_COMMON_TOKENIZERS_BRACECLOSE_H

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            class BraceClose {

            public:
                BraceClose() = default;
                BraceClose(const BraceClose &) = default;
                BraceClose(BraceClose &&) = default;
                BraceClose &operator=(const BraceClose &) = default;
                BraceClose &operator=(BraceClose &&) = default;
                virtual ~BraceClose() = default;
            };
        }
    }
}


#endif //CLDEPARSER_COMMON_TOKENIZERS_BRACECLOSE_H
