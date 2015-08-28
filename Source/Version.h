//
// Created by LE, Duc Anh on 8/27/15.
//

#ifndef CLDEPARSER_VERSION_H
#define CLDEPARSER_VERSION_H

#include <memory>
#include <string>

namespace CLDEParser {

    struct Version {

        std::string version{"v0.9.3"};
        void Print();

        // Factory methods
        static std::unique_ptr<Version> Create() {
            return std::unique_ptr<Version>(new Version());
        };
    };

    using UPtrVersion = std::unique_ptr<Version>;
    using SPtrVersion = std::shared_ptr<Version>;
}

#endif //CLDEPARSER_VERSION_H
