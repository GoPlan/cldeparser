//
// Created by LE, Duc Anh on 8/3/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_STRING_H
#define CLDEPARSER_SCANNING_TOKENIZERS_STRING_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CldeParser {
    namespace Scanning {
        namespace Tokenizers {

            class String : public Tokenizer {

                enum class States {
                    Start = 0,
                    InProgress = 1,
                    InProgressAlternative = 2,
                    InPogresssAlternativeHex_1 = 3,
                    InPogresssAlternativeHex_2 = 4,
                    InPogresssAlternativeHex_3 = 5,
                    InPogresssAlternativeHex_4 = 6,
                    Closing = 7
                };

                static StateSet _completeStates;
                static StateSet _acceptedStates;
                static TransitionMap _transitions;

                bool isControlCharacter(char character);
                bool isQuote(char character);
                bool isDoubleQuote(char character);
                bool isBackSlash(char character);
                bool isAlternativeSymbol(char character);
                bool isAlternativeHexSymbol(char character);
                bool isHexadecimal(char character);


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


#endif //CLDEPARSER_SCANNING_TOKENIZERS_STRING_H
