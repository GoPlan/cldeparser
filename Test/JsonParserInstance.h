//
// Created by LE, Duc Anh on 8/25/15.
//

#ifndef CLDEPARSER_TEST_PARSERINSTANCE_H
#define CLDEPARSER_TEST_PARSERINSTANCE_H

#include "../Source/CldeParser.h"

namespace CLDEParser {
    namespace Test {

        class JsonParserInstance {

            Scanner _scanner;
            ParserSingle _parser;

            void init();

        public:
            JsonParserInstance();
            JsonParserInstance(const JsonParserInstance &) = default;
            JsonParserInstance(JsonParserInstance &&) = default;
            JsonParserInstance &operator=(const JsonParserInstance &) = default;
            JsonParserInstance &operator=(JsonParserInstance &&) = default;
            virtual ~JsonParserInstance() = default;

            // Accessors & Mutators
            Scanner &scanner() { return _scanner; }
            ParserSingle &parser() { return _parser; }

            // Locals
            Parsing::Json::SPtrJsonEntity Parse(std::string const &json) const;
        };
    }
}


#endif //CLDEPARSER_TEST_PARSERINSTANCE_H
