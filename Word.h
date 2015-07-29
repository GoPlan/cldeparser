//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_WORD_H
#define CLDEPARSER_WORD_H

#include <string>
#include <vector>

namespace CldeParser {

    class Word {

        int _position;
        std::string _value;

    public:
        Word() = default;
        Word(const std::string &word, int position = 0);
        Word(const char *word, int position = 0);
        Word(const Word &) = default;
        Word(Word &&) = default;
        Word &operator=(const Word &) = default;
        Word &operator=(Word &&) = default;
        virtual ~Word() = default;
    };

    using SPtrWord = std::shared_ptr<Word>;
    using SPtrWordVector = std::vector<SPtrWord>;

    SPtrWord CreateWord();
}


#endif //CLDEPARSER_WORD_H
