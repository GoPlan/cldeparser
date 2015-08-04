//
// Created by LE, Duc Anh on 7/31/15.
//

#ifndef CLDEPARSER_CORE_ICOMPARABLE_H
#define CLDEPARSER_CORE_ICOMPARABLE_H

namespace CldeParser {
    namespace Core {
        struct IComparable {
            virtual bool Lesser(const IComparable &target) = 0;
            virtual bool Greater(const IComparable &target) = 0;
            virtual bool Equal(const IComparable &target) = 0;
        };
    }
}

#endif //CLDEPARSER_CORE_ICOMPARABLE_H
