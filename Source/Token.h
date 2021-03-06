//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_TOKEN_H
#define CLDEPARSER_TOKEN_H

#include <string>
#include <vector>
#include "Common/IPrintable.h"

namespace CLDEParser {

    class Token : public Common::IPrintable,
                  public std::enable_shared_from_this<Token> {

    public:
        Token(int id, const std::string &word) : _id{id}, _lexeme{word} { };
        Token(int id, int index, std::string const &word) : _id{id}, _index{index}, _lexeme{word} { };
        Token(int id, const char *word) : _id{id}, _lexeme{word} { };
        Token(const Token &) = default;
        Token(Token &&) = default;
        Token &operator=(const Token &) = default;
        Token &operator=(Token &&) = default;
        virtual ~Token() = default;

        // Accessors
        int id() const { return _id; }
        const std::string &lexeme() const { return _lexeme; }

        // IPrintable
        std::string CopyToString() const override;
        std::string CopyToString(const Common::IPrintFormatter &formatter) const override;

    protected:
        int _id;
        int _index;
        std::string _lexeme;
    };

    using SPtrToken = std::shared_ptr<Token>;
    using SPtrTokenVector = std::vector<SPtrToken>;
    using SPtrTokenVectorIterator = SPtrTokenVector::const_iterator;
    using SPtrTokenSet = std::vector<SPtrToken>;
    using SPtrTokenSetIterator = SPtrTokenSet::iterator;

    SPtrToken CreateSPtrToken(int id, const std::string &lexeme);
    SPtrToken CreateSPtrToken(int id, int index, std::string const &lexeme);
}


#endif //CLDEPARSER_TOKEN_H
