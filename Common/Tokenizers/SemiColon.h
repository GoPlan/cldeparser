//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_COMMON_TOKENIZERS_SEMICOLON_H
#define CLDEPARSER_COMMON_TOKENIZERS_SEMICOLON_H

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            class SemiColon {

            public:
                SemiColon() = default;
                SemiColon(const SemiColon &) = default;
                SemiColon(SemiColon &&) = default;
                SemiColon &operator=(const SemiColon &) = default;
                SemiColon &operator=(SemiColon &&) = default;
                ~SemiColon() = default;
            };
        }
    }
}


#endif //CLDEPARSER_COMMON_TOKENIZERS_SEMICOLON_H
