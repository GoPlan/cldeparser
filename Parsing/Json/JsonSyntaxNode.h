//
// Created by LE, Duc Anh on 8/13/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONSYNTAXNODE_H
#define CLDEPARSER_PARSING_JSON_JSONSYNTAXNODE_H

namespace CldeParser {
    namespace Parsing {
        namespace Json {

            class JsonSyntaxNode {

            public:
                JsonSyntaxNode() = default;
                JsonSyntaxNode(const JsonSyntaxNode &) = default;
                JsonSyntaxNode(JsonSyntaxNode &&) = default;
                JsonSyntaxNode &operator=(const JsonSyntaxNode &) = default;
                JsonSyntaxNode &operator=(JsonSyntaxNode &&) = default;
                virtual ~JsonSyntaxNode() = default;
            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONSYNTAXNODE_H
