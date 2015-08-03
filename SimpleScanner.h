//
// Created by LE, Duc Anh on 8/3/15.
//

#ifndef CLDEPARSER_SIMPLESCANNER_H
#define CLDEPARSER_SIMPLESCANNER_H

namespace CldeParser{

    class SimpleScanner {

    public:
        SimpleScanner() = default;
        SimpleScanner(const SimpleScanner &) = default;
        SimpleScanner(SimpleScanner &&) = default;
        SimpleScanner &operator=(const SimpleScanner &) = default;
        SimpleScanner &operator=(SimpleScanner &&) = default;
        virtual ~SimpleScanner() = default;
    };
}



#endif //CLDEPARSER_SIMPLESCANNER_H
