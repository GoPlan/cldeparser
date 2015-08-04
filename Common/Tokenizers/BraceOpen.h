//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_COMMON_TOKENIZERS_BRACEOPEN_H
#define CLDEPARSER_COMMON_TOKENIZERS_BRACEOPEN_H

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            class BraceOpen {

            public:
                BraceOpen() = default;
                BraceOpen(const BraceOpen &) = default;
                BraceOpen(BraceOpen &&) = default;
                BraceOpen &operator=(const BraceOpen &) = default;
                BraceOpen &operator=(BraceOpen &&) = default;
                virtual ~BraceOpen() = default;
            };
        }
    }
}


#endif //CLDEPARSER_COMMON_TOKENIZERS_BRACEOPEN_H
