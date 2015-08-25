#ifndef CLDEPARSER_TEST_CASE00_FEATURETEST_HPP
#define CLDEPARSER_TEST_CASE00_FEATURETEST_HPP

#include "JsonTestFixture.h"

namespace CLDEParser {
    namespace Test {

        TEST_F(JsonTestFixture, empty_object) {
            std::string example{};
            auto sptrJson = parserInstance().Parse(example);
            ASSERT_TRUE(sptrJson.get() == nullptr);
        }

        TEST_F(JsonTestFixture, simple_string) {
            std::string example{"{\"v\": \"1\" }"};
            auto sptrJson = parserInstance().Parse(example);
            auto sptrJsonObject = std::dynamic_pointer_cast<Parsing::Json::JsonObject>(sptrJson);
            ASSERT_TRUE(sptrJson.get() != nullptr);
            ASSERT_TRUE(sptrJson->Type() == Parsing::Json::JsonEntityType::Object);
            ASSERT_TRUE(sptrJsonObject->GetValue("v")->Type() == Parsing::Json::JsonValueType::String);
            ASSERT_TRUE(sptrJsonObject->GetValue("v")->strValue.compare("1") == 0);
        }

        // TODO: space tester

        TEST_F(JsonTestFixture, simple_int) {
            std::string example{"{\"v\": 1 }"};
            auto sptrJson = parserInstance().Parse(example);
            auto sptrJsonObject = std::dynamic_pointer_cast<Parsing::Json::JsonObject>(sptrJson);
            ASSERT_TRUE(sptrJson.get() != nullptr);
            ASSERT_TRUE(sptrJson->Type() == Parsing::Json::JsonEntityType::Object);
            ASSERT_TRUE(sptrJsonObject->GetValue("v")->Type() == Parsing::Json::JsonValueType::Integer);
            ASSERT_TRUE(sptrJsonObject->GetValue("v")->intValue == 1);
        }
    }
}

#endif//CLDEPARSER_TEST_CASE00_FEATURETEST_HPP