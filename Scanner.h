//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_SCANNER_H
#define CLDEPARSER_SCANNER_H

#include <vector>
#include <initializer_list>
#include <functional>
#include <unordered_map>
#include "Word.h"

namespace CldeParser {

    using TransitionKeyPair = std::pair<int, char>;
    using TransitionFunction = std::function<int(TransitionKeyPair)>;

    class Scanner {

        std::vector<int> _completeStates;
        std::vector<int> _acceptedStates;
        std::vector<char> _characters;
        std::vector<SPtrWord> _words;

        int _currentState{0};

        std::unordered_map<TransitionKeyPair, TransitionFunction> _transitionFunctions;

    public:
        Scanner() = default;
        Scanner(std::initializer_list<int> &completeStates,
                std::initializer_list<int> &acceptedStates,
                std::initializer_list<char> &characters);
        Scanner(const Scanner &) = default;
        Scanner(Scanner &&) = default;
        Scanner &operator=(const Scanner &) = default;
        Scanner &operator=(Scanner &&) = default;
        virtual ~Scanner() = default;

        void Execute(const std::string &buffer);
    };
}


#endif //CLDEPARSER_SCANNER_H
