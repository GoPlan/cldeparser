//
// Created by LE, Duc Anh on 8/13/15.
//

#include "JsonSyntaxNode.h"


namespace CldeParser {
    namespace Parsing {
        namespace Json {
            JsonSyntaxNode::JsonSyntaxNode(int id, std::string const &value)
                    : SyntaxNode{id, value} {
                //
            }

            std::string JsonSyntaxNode::CopyToString() const {
                std::string msg{};
                msg.reserve(20);
                msg += "(";
                msg += std::to_string(_id);
                msg += ",";
                msg += _value;
                msg += ")";
                return msg;
            }
        }
    }
}

