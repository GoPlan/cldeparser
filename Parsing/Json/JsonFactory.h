//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONFACTORY_H
#define CLDEPARSER_PARSING_JSON_JSONFACTORY_H

namespace CldeParser {
    namespace Parser {
        namespace Json {
            class JsonFactory {
            public:
                JsonFactory() = default;
                JsonFactory(const JsonFactory &) = default;
                JsonFactory(JsonFactory &&) = default;
                JsonFactory &operator=(const JsonFactory &) = default;
                JsonFactory &operator=(JsonFactory &&) = default;
                virtual ~JsonFactory() = default;
            };
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONFACTORY_H
