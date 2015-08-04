//
// Created by LE, Duc Anh on 8/3/15.
//

#include "Tokenizer.h"

namespace CldeParser {

    bool Tokenizer::IsValid(char character) {
        return true;
    }

    bool Tokenizer::BeginWithCharacter(char character) {

        auto transitionIter = Transitions().find(0);

        if (transitionIter == Transitions().cend()) { return false; }

        auto actionMap = (*transitionIter).second;
        auto actionIter = actionMap.find(character);

        return actionIter != actionMap.cend();
    }

    bool Tokenizer::Validate(char character) {
        if (!IsValid(character)) { return false; }
        return CoreValidate(character);
    }

    void Tokenizer::Reset() {
        _currentState = 0;
        _lexeme.clear();
    }

    SPtrToken Tokenizer::CreateSPtrToken() {
        return CldeParser::CreateSPtrToken(0, _lexeme);
    }

    bool Tokenizer::CoreValidate(char character) {

        auto transitionIter = Transitions().find(_currentState);

        if (transitionIter == Transitions().cend()) { return false; }

        auto actionMap = (*transitionIter).second;
        auto actionIter = actionMap.find(character);

        if (actionIter == actionMap.cend()) { return false; }

        _currentState = actionIter->second;

        return true;
    }
}


