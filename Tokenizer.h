//
// Created by LE, Duc Anh on 8/3/15.
//

#ifndef CLDEPARSER_TOKENIZER_H
#define CLDEPARSER_TOKENIZER_H

#include <set>
#include <vector>
#include <unordered_map>
#include <string>

namespace CldeParser {

    using StateSet = std::set<int>;

    class Tokenizer {

        StateSet _completeStates;
        StateSet _acceptedStates;

        int _currentState{0};
        std::string _lexeme{};

    public:
        Tokenizer() = default;
        Tokenizer(const Tokenizer &) = default;
        Tokenizer(Tokenizer &&) = default;
        Tokenizer &operator=(const Tokenizer &) = default;
        Tokenizer &operator=(Tokenizer &&) = default;
        virtual ~Tokenizer() = default;
    };
}


#endif //CLDEPARSER_TOKENIZER_H
