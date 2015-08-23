//
// Created by LE, Duc Anh on 8/3/15.
//

#ifndef CLDEPARSER_TOKENIZER_H
#define CLDEPARSER_TOKENIZER_H

#include <set>
#include <vector>
#include <unordered_map>
#include <string>
#include <list>
#include "Token.h"

namespace CLDEParser {

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
        bool Validate(char character);
        void Reset();

        // Locals (Virtuals)
        virtual const StateSet &CompleteStates() const = 0;
        virtual const StateSet &AcceptedStates() const = 0;
        virtual const TransitionMap &Transitions() const = 0;
        virtual bool BeginWithCharacter(char character);
        virtual SPtrToken CreateSPtrToken();

    protected:
        int _currentState{0};
        std::string _lexeme{};

        virtual bool IsValid(char character);
        virtual bool CoreValidate(char character);
    };

    using SPtrTokenizer = std::shared_ptr<Tokenizer>;
    using SPtrTokenizerVector = std::vector<SPtrTokenizer>;
    using SPtrTokenizerList = std::list<SPtrTokenizer>;
}


#endif //CLDEPARSER_TOKENIZER_H
