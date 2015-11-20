//
// Created by LE, Duc Anh on 8/10/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_ANGLEBRACKETOPEN_H
#define CLDEPARSER_SCANNING_TOKENIZERS_ANGLEBRACKETOPEN_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            class AngleBracketOpen : public Tokenizer {

            public:
                AngleBracketOpen() = default;
                AngleBracketOpen(const AngleBracketOpen &) = default;
                AngleBracketOpen(AngleBracketOpen &&) = default;
                AngleBracketOpen &operator=(const AngleBracketOpen &) = default;
                AngleBracketOpen &operator=(AngleBracketOpen &&) = default;
                ~AngleBracketOpen() = default;

                // Tokenizer
                bool BeginWithCharacter(char character) override;
                const StateSet &CompleteStates() const override;
                const StateSet &AcceptedStates() const override;
                const TransitionMap &Transitions() const override;
                SPtrToken CreateSPtrToken() override;

            protected:
                bool IsValid(char character) override;
                bool CoreValidate(char character) override;
            };
        }
    }
}


#endif //CLDEPARSER_SCANNING_TOKENIZERS_ANGLEBRACKETOPEN_H
