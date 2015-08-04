//
// Created by LE, Duc Anh on 8/3/15.
//

#ifndef CLDEPARSER_COMMON_TOKENIZERS_STRING_H
#define CLDEPARSER_COMMON_TOKENIZERS_STRING_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exception/ScannerException.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            class String : public Tokenizer {

                enum class States {
                    Start = 0,
                    InProgress = 1,
                    Closing = 2
                };

                static StateSet _completeStates;
                static StateSet _acceptedStates;
                static TransitionMap _transitions;

                bool isControlCharacter(char character);
                bool isQuote(char character);
                bool isBackSlash(char character);


            public:
                String() = default;
                String(const String &) = default;
                String(String &&) = default;
                String &operator=(const String &) = default;
                String &operator=(String &&) = default;
                ~String() = default;

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


#endif //CLDEPARSER_COMMON_TOKENIZERS_STRING_H
