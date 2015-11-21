//
// Created by LE, Duc Anh on 8/13/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONSYNTAXMODEL_H
#define CLDEPARSER_PARSING_JSON_JSONSYNTAXMODEL_H

#include <cldeparser/SyntaxModel.h>
#include "JsonEntity.h"
#include "JsonEntityFactory.h"
#include "JsonObject.h"
#include "JsonArray.h"
#include "JsonValue.h"
#include "JsonValueFactory.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            struct JsonSyntaxModelImpl;

            class JsonSyntaxModel : public SyntaxModel,
                                    public std::enable_shared_from_this<JsonSyntaxModel>,
                                    public Common::IPrintable {

                JsonSyntaxModelImpl *_ptrImpl = nullptr;

                friend class JsonDerivative;
                friend class JsonSyntaxModelHelper;

            public:
                JsonSyntaxModel();
                JsonSyntaxModel(JsonSyntaxModel const &);
                JsonSyntaxModel &operator=(JsonSyntaxModel const &);
                ~JsonSyntaxModel();

                // SyntaxModel
                void Reset() override;
                void AddLexeme(int id, std::string const &lexeme);

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
