//
// Created by LE, Duc Anh on 8/23/15.
//

#include "TokenizerFormatter.h"
#include "../../Token.h"

namespace CLDEParser {
    namespace Scanning {
        namespace Formatter {

            std::string TokenizerFormatter::Print(const Common::IPrintable &printable) const {
                auto const &sptrToken = dynamic_cast<SPtrToken const &>(printable);
                return std::string {"<" + std::to_string(sptrToken->id()) + ", " + sptrToken->lexeme() + ">"};
            }
        }
    }
}
