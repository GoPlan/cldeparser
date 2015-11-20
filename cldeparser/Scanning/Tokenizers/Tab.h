//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_TAB_H
#define CLDEPARSER_SCANNING_TOKENIZERS_TAB_H

#include "../../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            class Tab : public Tokenizer {

            public:
                Tab() = default;
                Tab(const Tab &) = default;
                Tab(Tab &&) = default;
                Tab &operator=(const Tab &) = default;
                Tab &operator=(Tab &&) = default;
                ~Tab() = default;

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

#endif //CLDEPARSER_SCANNING_TOKENIZERS_TAB_H
