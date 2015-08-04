//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_COMMON_TOKENIZERS_COLON_H
#define CLDEPARSER_COMMON_TOKENIZERS_COLON_H

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            class Colon {

            public:
                Colon() = default;
                Colon(const Colon &) = default;
                Colon(Colon &&) = default;
                Colon &operator=(const Colon &) = default;
                Colon &operator=(Colon &&) = default;
                virtual ~Colon() = default;
            };
        }
    }
}


#endif //CLDEPARSER_COMMON_TOKENIZERS_COLON_H
