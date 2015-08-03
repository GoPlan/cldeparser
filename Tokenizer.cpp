//
// Created by LE, Duc Anh on 8/3/15.
//

#include "Tokenizer.h"

namespace CldeParser {

    bool Tokenizer::BeginWithCharacter(char character) {
        return Validate(character, false);
    }

    bool Tokenizer::Validate(char character, bool isMoved) {

        auto transitionIter = _transitionMap.find(_currentState);

        if (transitionIter == _transitionMap.cend()) {
            return false;
        }

        auto actionMap = (*transitionIter).second;
        auto actionIter = actionMap.find(character);

        if (actionIter == actionMap.cend()) {
            return false;
        }

        if (isMoved)
            _currentState = actionIter->second;

        return true;
    }

    SPtrToken Tokenizer::CreateToken() {
        return CreateSPtrToken(0, _lexeme);
    }
}


