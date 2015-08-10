//
// Created by LE, Duc Anh on 8/10/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_BACKWARDSLASH_H
#define CLDEPARSER_SCANNING_TOKENIZERS_BACKWARDSLASH_H

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            class BackwardSlash {

            public:
                BackwardSlash() = default;
                BackwardSlash(const BackwardSlash &) = default;
                BackwardSlash(BackwardSlash &&) = default;
                BackwardSlash &operator=(const BackwardSlash &) = default;
                BackwardSlash &operator=(BackwardSlash &&) = default;
                virtual ~BackwardSlash() = default;
            };
        }
    }
}


#endif //CLDEPARSER_SCANNING_TOKENIZERS_BACKWARDSLASH_H
