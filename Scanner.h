//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_SCANNER_H
#define CLDEPARSER_SCANNER_H

#include <vector>
#include <initializer_list>
#include <functional>
#include <unordered_map>
#include "Common/IPrintable.h"
#include "Token.h"
#include "State.h"

namespace CldeParser {

    using TransitionKey = std::pair<SPtrState, char>;
    using TransitionMap = std::unordered_map<TransitionKey, SPtrState>;
    using CharacterVector = std::vector<char>;

    class Scanner : Common::IPrintable {

        SPtrStateVector _completeStates;
        SPtrStateVector _acceptedStates;
        SPtrState _currentState;
        TransitionMap _transitionMap;
        CharacterVector _characterVector;

    public:
        Scanner() = default;
        Scanner(std::initializer_list<SPtrState> &completeStates,
                std::initializer_list<SPtrState> &acceptedStates,
                std::initializer_list<char> &characters);
        Scanner(const Scanner &) = default;
        Scanner(Scanner &&) = default;
        Scanner &operator=(const Scanner &) = default;
        Scanner &operator=(Scanner &&) = default;
        virtual ~Scanner() = default;

        // IPrintable
        std::string CopyToString();

        // Locals
        void Execute(const std::string &buffer);
    };
}


#endif //CLDEPARSER_SCANNER_H
