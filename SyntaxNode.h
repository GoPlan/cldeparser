//
// Created by LE, Duc Anh on 8/10/15.
//

#ifndef CLDEPARSER_SYNTAXNODE_H
#define CLDEPARSER_SYNTAXNODE_H

#include "Token.h"

namespace CldeParser {

    class SyntaxNode : Token {

    public:
        SyntaxNode() = default;
        SyntaxNode(const SyntaxNode &) = default;
        SyntaxNode(SyntaxNode &&) = default;
        SyntaxNode &operator=(const SyntaxNode &) = default;
        SyntaxNode &operator=(SyntaxNode &&) = default;
        virtual ~SyntaxNode() = default;
    };
}


#endif //CLDEPARSER_SYNTAXNODE_H
