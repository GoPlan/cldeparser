//
// Created by LE, Duc Anh on 8/12/15.
//

#include "ParserFactory.h"
#include "Json/JsonDerivative.h"

namespace CLDEParser {
    namespace Parsing {

        UPtrDerivative ParserFactory::CreateJsonDerivativeInstance() {
            return std::unique_ptr<Json::JsonDerivative>(new Json::JsonDerivative());
        }
    }
}


