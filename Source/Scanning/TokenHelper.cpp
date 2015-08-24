//
// Created by LE, Duc Anh on 8/24/15.
//

#include "TokenHelper.h"
#include "TokenType.h"

namespace CLDEParser {
    namespace Scanning {

        std::vector<int> TokenHelper::DefaultFilterCodes() {
            return {(int) TokenType::Space, (int) TokenType::Tab};
        }

        CLDEParser::SPtrTokenVector TokenHelper::Filter(std::vector<int> const &filteredCodes,
                                                        const CLDEParser::SPtrTokenVector &tokens) {

            SPtrTokenVector filtered(tokens.size());

            // Remove Space tokens
            std::copy_if(tokens.cbegin(), tokens.cend(), filtered.begin(),
                         [filteredCodes](SPtrToken const &token) -> bool {

                             for (auto &code : filteredCodes) {
                                 if (code == token->id())
                                     return false;
                             }

                             return true;
                         });

            filtered.shrink_to_fit();

            return filtered;
        }
    }
}

