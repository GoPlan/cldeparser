//
// Created by LE, Duc Anh on 8/19/15.
//

#ifndef CLDEPARSER_PARSING_JSON_TABLES_JSONTYPETABLE_H
#define CLDEPARSER_PARSING_JSON_TABLES_JSONTYPETABLE_H

namespace CLDEParser {
    namespace Parsing {
        namespace Json {
            namespace Tables {

                class JsonTypeTable {

                public:
                    JsonTypeTable() = default;
                    JsonTypeTable(const JsonTypeTable &) = default;
                    JsonTypeTable(JsonTypeTable &&) = default;
                    JsonTypeTable &operator=(const JsonTypeTable &) = default;
                    JsonTypeTable &operator=(JsonTypeTable &&) = default;
                    virtual ~JsonTypeTable() = default;
                };
            }
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_TABLES_JSONTYPETABLE_H
