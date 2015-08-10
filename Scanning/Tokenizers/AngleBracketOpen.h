//
// Created by LE, Duc Anh on 8/10/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_ANGLEBRACKETOPEN_H
#define CLDEPARSER_SCANNING_TOKENIZERS_ANGLEBRACKETOPEN_H

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            class AngleBracketOpen {

            public:
                AngleBracketOpen() = default;
                AngleBracketOpen(const AngleBracketOpen &) = default;
                AngleBracketOpen(AngleBracketOpen &&) = default;
                AngleBracketOpen &operator=(const AngleBracketOpen &) = default;
                AngleBracketOpen &operator=(AngleBracketOpen &&) = default;
                virtual ~AngleBracketOpen() = default;
            };
        }
    }
}


#endif //CLDEPARSER_SCANNING_TOKENIZERS_ANGLEBRACKETOPEN_H
