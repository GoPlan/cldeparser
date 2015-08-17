//
// Created by LE, Duc Anh on 8/10/15.
//

#ifndef CLDEPARSER_SYNTAXNODE_H
#define CLDEPARSER_SYNTAXNODE_H

#include <string>
#include "Core/IPrintable.h"

namespace CldeParser {

    class SyntaxNode : public Core::IPrintable {

    public:
        SyntaxNode(int id, std::string const &value);
        SyntaxNode() = default;
        SyntaxNode(const SyntaxNode &) = default;
        SyntaxNode(SyntaxNode &&) = default;
        SyntaxNode &operator=(const SyntaxNode &) = default;
        SyntaxNode &operator=(SyntaxNode &&) = default;
        virtual ~SyntaxNode() = default;

        // Mutators & Accessors
        int id() const { return _id; }
        const std::string &value() const { return _value; }
        void setId(int id) { _id = id; }
        void setValue(const std::string &value) { _value = value; }

    protected:
        int _id;
        std::string _value;

    };

    using SPtrSyntaxNode = std::shared_ptr<SyntaxNode>;
}


#endif //CLDEPARSER_SYNTAXNODE_H
