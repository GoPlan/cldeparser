//
// Created by LE, Duc Anh on 8/10/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_FORWARDSLASH_H
#define CLDEPARSER_SCANNING_TOKENIZERS_FORWARDSLASH_H

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            class ForwardSlash {

            public:
                ForwardSlash() = default;
                ForwardSlash(const ForwardSlash &) = default;
                ForwardSlash(ForwardSlash &&) = default;
                ForwardSlash &operator=(const ForwardSlash &) = default;
                ForwardSlash &operator=(ForwardSlash &&) = default;
                virtual ~ForwardSlash() = default;
            };
        }
    }
}


#endif //CLDEPARSER_SCANNING_TOKENIZERS_FORWARDSLASH_H
