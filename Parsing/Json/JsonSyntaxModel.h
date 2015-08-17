//
// Created by LE, Duc Anh on 8/13/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONSYNTAXMODEL_H
#define CLDEPARSER_PARSING_JSON_JSONSYNTAXMODEL_H

#include "../../SyntaxModel.h"
#include "JsonEntity.h"
#include "JsonSyntaxNode.h"
#include "JsonObject.h"
#include "JsonArray.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {

            class JsonSyntaxModel : public SyntaxModel,
                                    public std::enable_shared_from_this<JsonSyntaxModel> {

                friend class JsonDerivative;
                friend class JsonSyntaxModelHelper;

                SPtrJsonEntityVector _sptrEntityScopeStack;
                SPtrJsonSyntaxNodeVector _sptrSyntaxNodeStack;

                SPtrJsonValue createSPtrJsonValue(SPtrJsonSyntaxNodeIterator &iterator);
                SPtrJsonEntity createSPtrJsonEntity(SPtrJsonSyntaxNodeIterator &iterator);

            public:
                JsonSyntaxModel() = default;
                JsonSyntaxModel(const JsonSyntaxModel &) = default;
                JsonSyntaxModel(JsonSyntaxModel &&) = default;
                JsonSyntaxModel &operator=(const JsonSyntaxModel &) = default;
                JsonSyntaxModel &operator=(JsonSyntaxModel &&) = default;
                virtual ~JsonSyntaxModel() = default;

                // SyntaxModel
                virtual void Reset() override;

                // Accessors & Mutators
                SPtrJsonEntityVector &EntityScopeStack() { return _sptrEntityScopeStack; }
                SPtrJsonSyntaxNodeVector &SyntaxNodeStack() { return _sptrSyntaxNodeStack; }

                // Locals
                SPtrJsonEntity CreateSPtrJsonEnity();

            };

            using SPtrJsonSyntaxModel = std::shared_ptr<JsonSyntaxModel>;
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONSYNTAXMODEL_H
