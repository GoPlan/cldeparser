//
// Created by LE, Duc Anh on 8/19/15.
//

#ifndef CLDEPARSER_PARSING_JSON_TABLES_JSONSYMBOLTABLE_H
#define CLDEPARSER_PARSING_JSON_TABLES_JSONSYMBOLTABLE_H

namespace CldeParser {
    namespace Parsing {
        namespace Json {
            namespace Tables {

                class JsonSymbolTable {

                public:
                    JsonSymbolTable() = default;
                    JsonSymbolTable(const JsonSymbolTable &) = default;
                    JsonSymbolTable(JsonSymbolTable &&) = default;
                    JsonSymbolTable &operator=(const JsonSymbolTable &) = default;
                    JsonSymbolTable &operator=(JsonSymbolTable &&) = default;
                    virtual ~JsonSymbolTable() = default;
                };
            }
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_TABLES_JSONSYMBOLTABLE_H
