//
// Created by LE, Duc Anh on 8/9/15.
//

#include "JsonEntityFactory.h"
#include "JsonObject.h"
#include "JsonArray.h"
#include "JsonDerivative.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            UPtrJsonEntity JsonEntityFactory::CreateJsonObjectInstance() {
                return std::unique_ptr<JsonEntity>(new JsonObject());
            }

            UPtrJsonEntity JsonEntityFactory::CreateJsonArrayInstance() {
                return std::unique_ptr<JsonEntity>(new JsonArray());
            }

//            UPtrJsonSyntaxNode JsonEntityFactory::CreateJsonSyntaxNodeInstance(int id, std::string const &value) {
//                return std::unique_ptr<JsonSyntaxNode>(new JsonSyntaxNode(id, value));
//            }
        }
    }
}


