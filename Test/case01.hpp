#ifndef CLDEPARSER_TEST_CASE01_HPP
#define CLDEPARSER_TEST_CASE01_HPP

#include "JsonTestFixture.h"

namespace CLDEParser {
    namespace Test {

        TEST_F(JsonTestFixture, case00_Empty) {
            std::string example{};
            auto jsonObj = parserInstance().Parse(example);
            ASSERT_TRUE(jsonObj.get() == nullptr);
        }
    }
}

#endif//CLDEPARSER_TEST_CASE01_HPP