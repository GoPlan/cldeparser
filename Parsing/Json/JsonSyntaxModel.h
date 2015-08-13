//
// Created by LE, Duc Anh on 8/13/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONSYNTAXMODEL_H
#define CLDEPARSER_PARSING_JSON_JSONSYNTAXMODEL_H

#include "../../SyntaxModel.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {

            class JsonSyntaxModel : public SyntaxModel {

                SPtrSyntaxNode _root;

            public:
                JsonSyntaxModel() = default;
                JsonSyntaxModel(const JsonSyntaxModel &) = default;
                JsonSyntaxModel(JsonSyntaxModel &&) = default;
                JsonSyntaxModel &operator=(const JsonSyntaxModel &) = default;
                JsonSyntaxModel &operator=(JsonSyntaxModel &&) = default;
                virtual ~JsonSyntaxModel() = default;

                // Accessors & Mutators
                virtual void Reset() override;
                virtual SPtrSyntaxNode const &RootNode() override;
            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONSYNTAXMODEL_H
