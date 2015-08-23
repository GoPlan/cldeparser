//
// Created by LE, Duc Anh on 8/12/15.
//

#include "ParserFactory.h"
#include "Json/JsonDerivative.h"

namespace CLDEParser {
    namespace Parsing {

        SPtrDerivative ParserFactory::CreateJsonDerivative() {
            return std::make_shared<Json::JsonDerivative>();
        }
    }
}


