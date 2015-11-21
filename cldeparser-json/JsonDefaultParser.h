//
// Created by Duc-Anh LE on 11/21/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONDEFAULTPARSER_H
#define CLDEPARSER_PARSING_JSON_JSONDEFAULTPARSER_H

#include "JsonEntity.h"

namespace CLDEParser {
    namespace Parsing {
        namespace Json {

            class JsonDefaultParser {

                struct JsonParserImpl;
                JsonParserImpl *_ptrImpl = nullptr;

            public:
                JsonDefaultParser();
                JsonDefaultParser(JsonDefaultParser const &jsonParser);
                JsonDefaultParser &operator=(JsonDefaultParser const &jsonParser);
                ~JsonDefaultParser();

                SPtrJsonEntity Parse(std::string const &json) const;
            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONDEFAULTPARSER_H
