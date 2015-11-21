
#include <gtest/gtest.h>
#include "JsonTestFixture.h"

namespace CLDEParser {
    namespace Test {

        TEST_F(JsonTestFixture, empty) {
            std::string example{};
            auto sptrJson = parserInstance().Parse(example);
            ASSERT_TRUE(sptrJson.get() == nullptr);
        }

        TEST_F(JsonTestFixture, empty_object) {
            std::string example{"{}"};
            auto sptrJson = parserInstance().Parse(example);
            ASSERT_TRUE(sptrJson.get() != nullptr);
            ASSERT_TRUE(sptrJson->Type() == Parsing::Json::JsonEntityType::Object);
        }

        TEST_F(JsonTestFixture, string_double_quote) {
            std::string example{"{\"xa\": \"astring\" }"};
            auto sptrJson = parserInstance().Parse(example);
            auto sptrJsonObject = Parsing::Json::JsonEntityHelper::ToSPtrObject(sptrJson);
            ASSERT_TRUE(sptrJson.get() != nullptr);
            ASSERT_TRUE(sptrJson->Type() == Parsing::Json::JsonEntityType::Object);
            ASSERT_TRUE(sptrJsonObject->GetValue("xa")->Type() == Parsing::Json::JsonValueType::String);
            ASSERT_TRUE(sptrJsonObject->GetValue("xa")->strValue.compare("astring") == 0);
        }

        TEST_F(JsonTestFixture, simple_id_string_double_quote) {
            std::string example{"{ xa: \"astring\" }"};
            auto sptrJson = parserInstance().Parse(example);
            auto sptrJsonObject = Parsing::Json::JsonEntityHelper::ToSPtrObject(sptrJson);
            ASSERT_TRUE(sptrJson.get() != nullptr);
            ASSERT_TRUE(sptrJson->Type() == Parsing::Json::JsonEntityType::Object);
            ASSERT_TRUE(sptrJsonObject->GetValue("xa")->Type() == Parsing::Json::JsonValueType::String);
            ASSERT_TRUE(sptrJsonObject->GetValue("xa")->strValue.compare("astring") == 0);
        }

        TEST_F(JsonTestFixture, string_single_quote) {
            std::string example{"{\"xa\": 'astring' }"};
            auto sptrJson = parserInstance().Parse(example);
            auto sptrJsonObject = Parsing::Json::JsonEntityHelper::ToSPtrObject(sptrJson);
            ASSERT_TRUE(sptrJson.get() != nullptr);
            ASSERT_TRUE(sptrJson->Type() == Parsing::Json::JsonEntityType::Object);
            ASSERT_TRUE(sptrJsonObject->GetValue("xa")->Type() == Parsing::Json::JsonValueType::String);
            ASSERT_TRUE(sptrJsonObject->GetValue("xa")->strValue.compare("astring") == 0);
        }

        TEST_F(JsonTestFixture, single_quote_in_string) {
            std::string example{"{\"xa\": \"as'tring\" }"};
            auto sptrJson = parserInstance().Parse(example);
            auto sptrJsonObject = Parsing::Json::JsonEntityHelper::ToSPtrObject(sptrJson);
            ASSERT_TRUE(sptrJson.get() != nullptr);
            ASSERT_TRUE(sptrJson->Type() == Parsing::Json::JsonEntityType::Object);
            ASSERT_TRUE(sptrJsonObject->GetValue("xa")->Type() == Parsing::Json::JsonValueType::String);
            ASSERT_TRUE(sptrJsonObject->GetValue("xa")->strValue.compare("as'tring") == 0);
        }

        TEST_F(JsonTestFixture, double_quote_in_string) {

            std::string example{"{\"xa\": 'as\"tring' }"};
            auto sptrJson = parserInstance().Parse(example);
            auto sptrJsonObject = Parsing::Json::JsonEntityHelper::ToSPtrObject(sptrJson);
            ASSERT_TRUE(sptrJson.get() != nullptr);
            ASSERT_TRUE(sptrJson->Type() == Parsing::Json::JsonEntityType::Object);
            ASSERT_TRUE(sptrJsonObject->GetValue("xa")->Type() == Parsing::Json::JsonValueType::String);
            ASSERT_TRUE(sptrJsonObject->GetValue("xa")->strValue.compare("as\"tring") == 0);
        }

        TEST_F(JsonTestFixture, integer) {
            std::string example{"{\"x\": 123456789 }"};
            auto sptrJson = parserInstance().Parse(example);
            auto sptrJsonObject = Parsing::Json::JsonEntityHelper::ToSPtrObject(sptrJson);
            ASSERT_TRUE(sptrJson.get() != nullptr);
            ASSERT_TRUE(sptrJson->Type() == Parsing::Json::JsonEntityType::Object);
            ASSERT_TRUE(sptrJsonObject->GetValue("x")->Type() == Parsing::Json::JsonValueType::Integer);
            ASSERT_TRUE(sptrJsonObject->GetValue("x")->intValue == 123456789);
        }

        TEST_F(JsonTestFixture, real) {
            std::string example{"{x: 123456.123 }"};
            auto sptrJson = parserInstance().Parse(example);
            auto sptrJsonObject = Parsing::Json::JsonEntityHelper::ToSPtrObject(sptrJson);
            ASSERT_TRUE(sptrJson.get() != nullptr);
            ASSERT_TRUE(sptrJson->Type() == Parsing::Json::JsonEntityType::Object);
            ASSERT_TRUE(sptrJsonObject->GetValue("x")->Type() == Parsing::Json::JsonValueType::Real);
            ASSERT_TRUE(sptrJsonObject->GetValue("x")->doubleValue == 123456.123);
        }

        TEST_F(JsonTestFixture, real_with_uppercase_exponential) {
            std::string example{"{x: 123456.123E+1 }"};
            auto sptrJson = parserInstance().Parse(example);
            auto sptrJsonObject = Parsing::Json::JsonEntityHelper::ToSPtrObject(sptrJson);
            ASSERT_TRUE(sptrJson.get() != nullptr);
            ASSERT_TRUE(sptrJson->Type() == Parsing::Json::JsonEntityType::Object);
            ASSERT_TRUE(sptrJsonObject->GetValue("x")->Type() == Parsing::Json::JsonValueType::Real);
            ASSERT_TRUE(sptrJsonObject->GetValue("x")->doubleValue == 123456.123E+1);
        }

        TEST_F(JsonTestFixture, real_with_lowercase_exponential) {
            std::string example{"{x: 123456.123e+2 }"};
            auto sptrJson = parserInstance().Parse(example);
            auto sptrJsonObject = Parsing::Json::JsonEntityHelper::ToSPtrObject(sptrJson);
            ASSERT_TRUE(sptrJson.get() != nullptr);
            ASSERT_TRUE(sptrJson->Type() == Parsing::Json::JsonEntityType::Object);
            ASSERT_TRUE(sptrJsonObject->GetValue("x")->Type() == Parsing::Json::JsonValueType::Real);
            ASSERT_TRUE(sptrJsonObject->GetValue("x")->doubleValue == 123456.123E+2);
        }

        TEST_F(JsonTestFixture, empty_array) {
            std::string example{"[]"};
            auto sptrJson = parserInstance().Parse(example);
            ASSERT_TRUE(sptrJson.get() != nullptr);
            ASSERT_TRUE(sptrJson->Type() == Parsing::Json::JsonEntityType::Array);
        }

        TEST_F(JsonTestFixture, multiple_empty_array) {
            std::string example{"[ { }, { },[ {}, {}], { array: [{}, {}, {}]}]"};
            auto sptrJson = parserInstance().Parse(example);
            ASSERT_TRUE(sptrJson.get() != nullptr);
            ASSERT_TRUE(sptrJson->Type() == Parsing::Json::JsonEntityType::Array);
            auto sptrJsonArray = Parsing::Json::JsonEntityHelper::ToSPtrArray(sptrJson);
            ASSERT_TRUE(sptrJsonArray->Container().size() == 4);
        }

        TEST_F(JsonTestFixture, array) {
            std::string example{"{x: [ 1234, 1243, 13.24, 13.42e+1, { y : [ 343, 3.43, 34.3e+1, 'astring'] } ] }"};
            auto sptrJson = parserInstance().Parse(example);
            auto sptrJsonObject = Parsing::Json::JsonEntityHelper::ToSPtrObject(sptrJson);
            ASSERT_TRUE(sptrJson.get() != nullptr);
            ASSERT_TRUE(sptrJson->Type() == Parsing::Json::JsonEntityType::Object);
            ASSERT_TRUE(sptrJsonObject->GetValue("x")->Type() == Parsing::Json::JsonValueType::Entity);
            auto sptrJsonObjectValue = sptrJsonObject->GetValue("x");
            auto sptrJsonArray = Parsing::Json::JsonEntityHelper::ToSPtrArray(sptrJsonObjectValue->sptrJsonEntity);
            ASSERT_TRUE(sptrJsonArray.get() != nullptr);
            ASSERT_TRUE(sptrJsonArray->Container().size() == 5);
        }

        TEST_F(JsonTestFixture, boolean_true_false) {
            std::string example{"{x: true, y :   false    }"};
            auto sptrJson = parserInstance().Parse(example);
            auto sptrJsonObject = Parsing::Json::JsonEntityHelper::ToSPtrObject(sptrJson);
            ASSERT_TRUE(sptrJson.get() != nullptr);
            ASSERT_TRUE(sptrJson->Type() == Parsing::Json::JsonEntityType::Object);
            ASSERT_TRUE(sptrJsonObject->GetValue("x")->Type() == Parsing::Json::JsonValueType::Boolean);
            ASSERT_TRUE(sptrJsonObject->GetValue("y")->Type() == Parsing::Json::JsonValueType::Boolean);
            auto sptrJsonValueX = sptrJsonObject->GetValue("x");
            auto sptrJsonValueY = sptrJsonObject->GetValue("y");
            ASSERT_TRUE(Parsing::Json::JsonValueHelper::ToBoolean(sptrJsonValueX));
            ASSERT_TRUE(!Parsing::Json::JsonValueHelper::ToBoolean(sptrJsonValueY));
        }
    }
}

