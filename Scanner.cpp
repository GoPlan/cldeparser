//
// Created by LE, Duc Anh on 7/29/15.
//

#include "Scanner.h"

namespace CldeParser {

    Scanner::Scanner(std::initializer_list<int> &completeStates,
                     std::initializer_list<int> &acceptedStates,
                     std::initializer_list<char> &characters)
            : _completeStates{completeStates},
              _acceptedStates{acceptedStates},
              _characters{characters} {
        //
    }

    void Scanner::Execute(const std::string &buffer) {

        std::string tmp;

        for (auto &item : buffer) {

            auto transPair = std::make_pair(_currentState, item);

            if (_transitionFunctions.find(transPair) == _transitionFunctions.cend()) {
                // TODO: throw an approriate exception
            }

            auto &transFunction = _transitionFunctions[transPair];
            _currentState = transFunction(transPair);

            // Check if _currentState is an E

            // Check if _currentState is acceptable

            // Else - continue;
        }
    }

    std::string Scanner::CopyToString() {
        return std::string{};
    }
}


