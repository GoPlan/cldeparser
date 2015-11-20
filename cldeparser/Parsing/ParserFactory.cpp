//
// Created by LE, Duc Anh on 8/12/15.
//

#include "JsonParserFactory.h"
#include "Json/JsonDerivative.h"

namespace CLDEParser {
    namespace Parsing {

        UPtrDerivative JsonParserFactory::CreateJsonDerivativeInstance() {
            return std::unique_ptr<Json::JsonDerivative>(new Json::JsonDerivative());
        }
    }
}


