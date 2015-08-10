//
// Created by LE, Duc Anh on 8/10/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_SQUAREBRACKETOPEN_H
#define CLDEPARSER_SCANNING_TOKENIZERS_SQUAREBRACKETOPEN_H

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            class SquareBracketOpen {

            public:
                SquareBracketOpen() = default;
                SquareBracketOpen(const SquareBracketOpen &) = default;
                SquareBracketOpen(SquareBracketOpen &&) = default;
                SquareBracketOpen &operator=(const SquareBracketOpen &) = default;
                SquareBracketOpen &operator=(SquareBracketOpen &&) = default;
                virtual ~SquareBracketOpen() = default;
            };
        }
    }
}


#endif //CLDEPARSER_SCANNING_TOKENIZERS_SQUAREBRACKETOPEN_H
