//
// Created by LE, Duc Anh on 8/13/15.
//

#include "JsonSyntaxModel.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {

            void JsonSyntaxModel::Reset() {
                _sptrSyntaxNodeStack.clear();
                _sptrEntityScopeStack.clear();
            }

            SPtrJsonEntity JsonSyntaxModel::CreateSPtrJsonEnity() {
                SPtrJsonEntity sptrEntity;
                return sptrEntity;
            }
        }
    }
}

