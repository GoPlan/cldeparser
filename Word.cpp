//
// Created by LE, Duc Anh on 7/29/15.
//

#include "Word.h"

namespace CldeParser {

    Word::Word(const std::string &word, int position)
            : _value{word}, _position{position} {
        //
    }

    Word::Word(const char *word, int position)
            : _value{word}, _position{position} {
        //
    }

    SPtrWord CreateWord(const std::string &value) {
        return std::make_shared<Word>(value);
    }
}


