//
// Created by LE, Duc Anh on 8/12/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONDERIVATIVEFACTORY_H
#define CLDEPARSER_PARSING_JSON_JSONDERIVATIVEFACTORY_H

#include <cldeparser/Derivative.h>

namespace CLDEParser {
    namespace Parsing {
        struct JsonDerivativeFactory {
            static UPtrDerivative CreateJsonDerivativeInstance();
        };
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONDERIVATIVEFACTORY_H
