//
// Created by LE, Duc Anh on 8/11/15.
//

#ifndef CLDEPARSER_PARSING_SIMPLEMATH_SIMPLEMATHDERIVATIVE_H
#define CLDEPARSER_PARSING_SIMPLEMATH_SIMPLEMATHDERIVATIVE_H

#include "../../Derivative.h"

namespace CldeParser {
    namespace Parsing {
        namespace SimpleMath {

            class SimpleMathDerivative : public Derivative {

            public:
                SimpleMathDerivative() = default;
                SimpleMathDerivative(const SimpleMathDerivative &) = default;
                SimpleMathDerivative(SimpleMathDerivative &&) = default;
                SimpleMathDerivative &operator=(const SimpleMathDerivative &) = default;
                SimpleMathDerivative &operator=(SimpleMathDerivative &&) = default;
                virtual ~SimpleMathDerivative() = default;
            };
        }
    }
}


#endif //CLDEPARSER_PARSING_SIMPLEMATH_SIMPLEMATHDERIVATIVE_H
