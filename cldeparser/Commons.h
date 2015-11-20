//
// Created by Duc-Anh LE on 11/20/15.
//

#ifndef CLDEPARSER_COMMONS_H
#define CLDEPARSER_COMMONS_H

#include <string>

namespace CLDEParser {
    namespace Common {

        struct IPrintable;
        struct IPrintFormatter;

        enum BufferSize {
            SIXTEEN = 16,
            THIRTYTWO = 32,
            SIXTYFOUR = 64,
            EIGHTY = 80
        };

        struct IComparable {
            virtual bool Lesser(const IComparable &target) = 0;
            virtual bool Greater(const IComparable &target) = 0;
            virtual bool Equal(const IComparable &target) = 0;
        };

        struct IPrintFormatter {
            virtual std::string Print(const IPrintable &printable) const = 0;
        };

        struct IPrintable {
            virtual std::string CopyToString() const = 0;
            virtual std::string CopyToString(IPrintFormatter const &formatter) const { return formatter.Print(*this); };
        };
    }
}
#endif //CLDEPARSER_COMMONS_H
