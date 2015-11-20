//
// Created by LE, Duc Anh on 8/10/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_ANGLEBRACKETCLOSING_H
#define CLDEPARSER_SCANNING_TOKENIZERS_ANGLEBRACKETCLOSING_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            class AngleBracketClosing : public Tokenizer {

            public:
                AngleBracketClosing() = default;
                AngleBracketClosing(const AngleBracketClosing &) = default;
                AngleBracketClosing(AngleBracketClosing &&) = default;
                AngleBracketClosing &operator=(const AngleBracketClosing &) = default;
                AngleBracketClosing &operator=(AngleBracketClosing &&) = default;
                ~AngleBracketClosing() = default;

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


#endif //CLDEPARSER_SCANNING_TOKENIZERS_ANGLEBRACKETCLOSING_H
