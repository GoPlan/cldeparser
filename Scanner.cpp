//
// Created by LE, Duc Anh on 7/29/15.
//

#include "Scanner.h"

namespace CldeParser {

    Scanner::Scanner(std::initializer_list<SPtrState> &completeStates,
                     std::initializer_list<SPtrState> &acceptedStates,
                     std::initializer_list<char> &characters)
            : _completeStates{completeStates},
              _acceptedStates{acceptedStates},
              _characterVector{characters} {
        //
    }

    void Scanner::Execute(const std::string &buffer) {

        std::string tmp;

        for (auto &item : buffer) {

            auto transitionKey = std::make_pair(_currentState, item);

            TransitionMap::iterator iter;

            if ((iter = _transitionMap.find(transitionKey)) == _transitionMap.cend()) {
                // TODO: throw an approriate exception
            }

            _currentState = iter->second;

            // Check if _currentState is acceptable

            // Check if _currentState is an E

            // Else - continue;
        }
    }

    std::string Scanner::CopyToString() {
        return std::string{};
    }
}


