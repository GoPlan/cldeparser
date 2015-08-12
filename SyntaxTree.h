//
// Created by LE, Duc Anh on 8/10/15.
//

#ifndef CLDEPARSER_SYNTAXTREE_H
#define CLDEPARSER_SYNTAXTREE_H

#include <memory>
#include "SyntaxNode.h"

namespace CldeParser {

    class SyntaxTree : public Core::IPrintable {

    public:
        SyntaxTree() = default;
        SyntaxTree(const SyntaxTree &) = default;
        SyntaxTree(SyntaxTree &&) = default;
        SyntaxTree &operator=(const SyntaxTree &) = default;
        SyntaxTree &operator=(SyntaxTree &&) = default;
        virtual ~SyntaxTree() = default;
        
        // Locals
        virtual void Reset();

    protected:
        SPtrSyntaxNode _root;

    };

    using SPtrSyntaxTree = std::shared_ptr<SyntaxTree>;
}


#endif //CLDEPARSER_SYNTAXTREE_H
