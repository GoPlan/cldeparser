//
// Created by LE, Duc Anh on 8/3/15.
//

#ifndef CLDEPARSER_TOKENIZER_H
#define CLDEPARSER_TOKENIZER_H

#include <set>
#include <vector>
#include <unordered_map>
#include <string>
#include "Token.h"

namespace CldeParser {

    using StateSet = std::set<int>;
    using ActionMap = std::unordered_map<char, int>;
    using TransitionMap = std::unordered_map<int, ActionMap>;

    class Tokenizer {

    public:
        Tokenizer() = default;
        Tokenizer(const Tokenizer &) = default;
        Tokenizer(Tokenizer &&) = default;
        Tokenizer &operator=(const Tokenizer &) = default;
        Tokenizer &operator=(Tokenizer &&) = default;
        virtual ~Tokenizer() = default;

        // Locals
        virtual bool BeginWithCharacter(char character);
        virtual bool Validate(char character, bool isMoved = true);
        virtual SPtrToken CreateToken();

    protected:
        StateSet _completeStates;
        StateSet _acceptedStates;
        TransitionMap _transitionMap;
        int _currentState{0};
        std::string _lexeme{};
    };

    using SPtrTokenizer = std::shared_ptr<Tokenizer>;
    using SPtrTokenizerVector = std::vector<SPtrTokenizer>;
}


#endif //CLDEPARSER_TOKENIZER_H
