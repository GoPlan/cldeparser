//
// Created by LE, Duc Anh on 8/17/15.
//

#include "JsonSyntaxModelHelper.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {

            bool JsonSyntaxModelHelper::HasCurrentScope(const SPtrJsonSyntaxModel &sptrSyntaxModel) {
                return sptrSyntaxModel->_sptrEntityScopeStack.size() > 0;
            }

            SPtrJsonEntity &JsonSyntaxModelHelper::CurrentScopeEntity(SPtrJsonSyntaxModel const &sptrSyntaxModel) {
                return sptrSyntaxModel->_sptrEntityScopeStack.back();
            }
        }
    }
}
