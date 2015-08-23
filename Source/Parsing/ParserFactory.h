//
// Created by LE, Duc Anh on 8/12/15.
//

#ifndef CLDEPARSER_PARSING_PARSERFACTORY_H
#define CLDEPARSER_PARSING_PARSERFACTORY_H

#include "../Derivative.h"

namespace CLDEParser {
    namespace Parsing {

        struct ParserFactory {
            static SPtrDerivative CreateJsonDerivative();
        };
    }
}


#endif //CLDEPARSER_PARSING_PARSERFACTORY_H
