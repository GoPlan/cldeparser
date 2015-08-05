//
// Created by LE, Duc Anh on 8/5/15.
//

#ifndef CLDEPARSER_PARSER_H
#define CLDEPARSER_PARSER_H

namespace CldeParser {

    class Parser {

    public:
        Parser() = default;
        Parser(const Parser &) = default;
        Parser(Parser &&) = default;
        Parser &operator=(const Parser &) = default;
        Parser &operator=(Parser &&) = default;
        virtual ~Parser() = default;
    };
}


#endif //CLDEPARSER_PARSER_H
