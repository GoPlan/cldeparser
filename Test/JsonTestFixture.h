//
// Created by LE, Duc Anh on 8/25/15.
//

#ifndef CLDEPARSER_TEST_JSONTESTFIXTURE_H
#define CLDEPARSER_TEST_JSONTESTFIXTURE_H

#include <gtest/gtest.h>
#include "JsonParserInstance.h"

namespace CLDEParser {
    namespace Test {

        class JsonTestFixture : public ::testing::Test {

            JsonParserInstance _parserInstance;

        public:
            JsonTestFixture() = default;
            JsonTestFixture(const JsonTestFixture &) = default;
            JsonTestFixture(JsonTestFixture &&) = default;
            JsonTestFixture &operator=(const JsonTestFixture &) = default;
            JsonTestFixture &operator=(JsonTestFixture &&) = default;
            virtual ~JsonTestFixture() = default;

            // Accessors
            const JsonParserInstance &parserInstance() const { return _parserInstance; }

        protected:
            virtual void SetUp() override;
            virtual void TearDown() override;
        };
    }
}


#endif //CLDEPARSER_TEST_JSONTESTFIXTURE_H
