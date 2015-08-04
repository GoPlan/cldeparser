//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_COMMON_TOKENIZERS_COMMA_H
#define CLDEPARSER_COMMON_TOKENIZERS_COMMA_H

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            class Comma {

            public:
                Comma() = default;
                Comma(const Comma &) = default;
                Comma(Comma &&) = default;
                Comma &operator=(const Comma &) = default;
                Comma &operator=(Comma &&) = default;
                virtual ~Comma() = default;
            };
        }
    }
}


#endif //CLDEPARSER_COMMON_TOKENIZERS_COMMA_H
