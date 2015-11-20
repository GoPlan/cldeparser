//
// Created by LE, Duc Anh on 8/25/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_LINEFEED_H
#define CLDEPARSER_SCANNING_TOKENIZERS_LINEFEED_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            class LineFeed : public Tokenizer {

            public:
                LineFeed() = default;
                LineFeed(const LineFeed &) = default;
                LineFeed(LineFeed &&) = default;
                LineFeed &operator=(const LineFeed &) = default;
                LineFeed &operator=(LineFeed &&) = default;
                ~LineFeed() = default;

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


#endif //CLDEPARSER_SCANNING_TOKENIZERS_LINEFEED_H
