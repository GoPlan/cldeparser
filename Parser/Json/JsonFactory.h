//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSER_JSONFACTORY_H
#define CLDEPARSER_PARSER_JSONFACTORY_H

namespace CldeParser {
    namespace Parser {

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


#endif //CLDEPARSER_PARSER_JSONFACTORY_H
