//
// Created by LE, Duc Anh on 7/31/15.
//

#ifndef CLDEPARSER_COMMON_ICOMPARABLE_H
#define CLDEPARSER_COMMON_ICOMPARABLE_H

namespace CldeParser {
    namespace Common {
        struct IComparable {
            virtual bool Lesser(const IComparable &target) = 0;
            virtual bool Greater(const IComparable &target) = 0;
            virtual bool Equal(const IComparable &target) = 0;
        };
    }
}

#endif //CLDEPARSER_COMMON_ICOMPARABLE_H
