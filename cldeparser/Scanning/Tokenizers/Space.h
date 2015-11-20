//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_SPACE_H
#define CLDEPARSER_SCANNING_TOKENIZERS_SPACE_H

#include "../../TokenType.h"
#include "../../Tokenizer.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            class Space : public Tokenizer {
            public:
                Space() = default;
                Space(const Space &) = default;
                Space(Space &&) = default;
                Space &operator=(const Space &) = default;
                Space &operator=(Space &&) = default;
                ~Space() = default;

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


#endif //CLDEPARSER_SCANNING_TOKENIZERS_SPACE_H
