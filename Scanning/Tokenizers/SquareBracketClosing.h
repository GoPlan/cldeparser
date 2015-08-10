//
// Created by LE, Duc Anh on 8/10/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_SQUAREBRACKETCLOSING_H
#define CLDEPARSER_SCANNING_TOKENIZERS_SQUAREBRACKETCLOSING_H

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            class SquareBracketClosing {

            public:
                SquareBracketClosing() = default;
                SquareBracketClosing(const SquareBracketClosing &) = default;
                SquareBracketClosing(SquareBracketClosing &&) = default;
                SquareBracketClosing &operator=(const SquareBracketClosing &) = default;
                SquareBracketClosing &operator=(SquareBracketClosing &&) = default;
                virtual ~SquareBracketClosing() = default;
            };
        }
    }
}


#endif //CLDEPARSER_SCANNING_TOKENIZERS_SQUAREBRACKETCLOSING_H
