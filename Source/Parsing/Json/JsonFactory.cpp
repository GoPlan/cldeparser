//
// Created by LE, Duc Anh on 8/9/15.
//

#include "JsonFactory.h"
#include "JsonObject.h"
#include "JsonArray.h"
#include "JsonDerivative.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            UPtrJsonEntity JsonFactory::CreateJsonObjectInstance() {
                return std::unique_ptr<JsonEntity>(new JsonObject());
            }

            UPtrJsonEntity JsonFactory::CreateJsonArrayInstance() {
                return std::unique_ptr<JsonEntity>(new JsonArray());
            }

            UPtrJsonSyntaxNode JsonFactory::CreateJsonSyntaxNodeInstance(int id, std::string const &value) {
                return std::unique_ptr<JsonSyntaxNode>(new JsonSyntaxNode(id, value));
            }
        }
    }
}


