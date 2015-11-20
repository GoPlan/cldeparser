//
// Created by LE, Duc Anh on 8/25/15.
//

#ifndef CLDEPARSER_SCANNING_TOKENIZERS_CARRIAGERETURN_H
#define CLDEPARSER_SCANNING_TOKENIZERS_CARRIAGERETURN_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exceptions/ScannerException.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Tokenizers {

            class CarriageReturn : public Tokenizer {

            public:
                CarriageReturn() = default;
                CarriageReturn(const CarriageReturn &) = default;
                CarriageReturn(CarriageReturn &&) = default;
                CarriageReturn &operator=(const CarriageReturn &) = default;
                CarriageReturn &operator=(CarriageReturn &&) = default;
                ~CarriageReturn() = default;

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

#endif //CLDEPARSER_SCANNING_TOKENIZERS_CARRIAGERETURN_H
