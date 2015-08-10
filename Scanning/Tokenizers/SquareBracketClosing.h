//
// Created by LE, Duc Anh on 8/10/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_SQUAREBRACKETCLOSING_H
#define CLDEPARSER_SCANNING_TOKENIZERS_SQUAREBRACKETCLOSING_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            class SquareBracketClosing : public Tokenizer {

            public:
                SquareBracketClosing() = default;
                SquareBracketClosing(const SquareBracketClosing &) = default;
                SquareBracketClosing(SquareBracketClosing &&) = default;
                SquareBracketClosing &operator=(const SquareBracketClosing &) = default;
                SquareBracketClosing &operator=(SquareBracketClosing &&) = default;
                ~SquareBracketClosing() = default;

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


#endif //CLDEPARSER_SCANNING_TOKENIZERS_SQUAREBRACKETCLOSING_H
