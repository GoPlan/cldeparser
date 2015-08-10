//
// Created by LE, Duc Anh on 8/10/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_ANGLEBRACKETCLOSING_H
#define CLDEPARSER_SCANNING_TOKENIZERS_ANGLEBRACKETCLOSING_H

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            class AngleBracketClosing {

            public:
                AngleBracketClosing() = default;
                AngleBracketClosing(const AngleBracketClosing &) = default;
                AngleBracketClosing(AngleBracketClosing &&) = default;
                AngleBracketClosing &operator=(const AngleBracketClosing &) = default;
                AngleBracketClosing &operator=(AngleBracketClosing &&) = default;
                virtual ~AngleBracketClosing() = default;
            };
        }
    }
}


#endif //CLDEPARSER_SCANNING_TOKENIZERS_ANGLEBRACKETCLOSING_H
