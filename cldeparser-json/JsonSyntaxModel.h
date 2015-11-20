//
// Created by LE, Duc Anh on 8/13/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONSYNTAXMODEL_H
#define CLDEPARSER_PARSING_JSON_JSONSYNTAXMODEL_H

#include <cldeparser/SyntaxModel.h>
#include "JsonEntity.h"
#include "JsonSyntaxNode.h"
#include "JsonValue.h"
#include "JsonException.h"


namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            class JsonSyntaxModel : public SyntaxModel,
                                    public std::enable_shared_from_this<JsonSyntaxModel>,
                                    public Common::IPrintable {

                friend class JsonDerivative;
                friend class JsonSyntaxModelHelper;

                SPtrJsonEntityVector _sptrEntityScopeStack;
                SPtrJsonSyntaxNodeVector _sptrSyntaxNodeQueue;

                SPtrJsonValue createSPtrJsonValue(SPtrJsonSyntaxNodeIterator &iterator);
                SPtrJsonEntity createSPtrJsonEntity(SPtrJsonSyntaxNodeIterator &iterator);

            public:
                JsonSyntaxModel() = default;
                JsonSyntaxModel(JsonSyntaxModel const &) = default;
                JsonSyntaxModel(JsonSyntaxModel &&) = default;
                JsonSyntaxModel &operator=(JsonSyntaxModel const &) = default;
                JsonSyntaxModel &operator=(JsonSyntaxModel &&) = default;
                ~JsonSyntaxModel() = default;

                // SyntaxModel
                void Reset() override;

                // IPrintable
                std::string CopyToString() const override;

                // Locals
                SPtrJsonEntity CreateSPtrJsonEnity();
            };

            using UPtrJsonSyntaxModel = std::unique_ptr<JsonSyntaxModel>;
            using SPtrJsonSyntaxModel = std::shared_ptr<JsonSyntaxModel>;
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONSYNTAXMODEL_H
