//
// Created by LE, Duc Anh on 8/28/15.
//

#ifndef CLDEPARSER_TEST_CASE01_ACTUALEXAMPLES_HPP
#define CLDEPARSER_TEST_CASE01_ACTUALEXAMPLES_HPP

#include <fstream>
#include "JsonTestFixture.h"

#define CUSTOMERMAP_JSON "JsonExamples/CustomerMap.json"

namespace CLDEParser {
    namespace Test {

        TEST_F(JsonTestFixture, CustomerMap) {

            char buffer[CLDEParser::Common::BufferSize::EIGHTY];
            memset(buffer, 0x0, CLDEParser::Common::BufferSize::EIGHTY);

            std::ifstream file{CUSTOMERMAP_JSON};
            ASSERT_TRUE(!file.operator!());

            std::string document((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            auto sptrJson = parserInstance().Parse(document);
            ASSERT_TRUE(sptrJson.operator->());
            ASSERT_TRUE(sptrJson->Type() == CLDEParser::Parsing::Json::JsonEntityType::Object);

            // Root
            auto sptrRoot = CLDEParser::Parsing::Json::JsonEntityHelper::ToSPtrObject(sptrJson);
            ASSERT_TRUE(sptrRoot.operator->());

            // Name
            auto sptrNameValue = sptrRoot->GetValue("Name");
            ASSERT_TRUE(sptrNameValue->Type() == CLDEParser::Parsing::Json::JsonValueType::String);
            ASSERT_TRUE(sptrNameValue->strValue == "Customer");

            // TableName
            auto sptrTableNameValue = sptrRoot->GetValue("TableName");
            ASSERT_TRUE(sptrTableNameValue->Type() == CLDEParser::Parsing::Json::JsonValueType::String);
            ASSERT_TRUE(sptrTableNameValue->strValue == "Customer");

            // ColumnsForGet
            auto sptrColumnsForGet = sptrRoot->GetValue("ColumnsForGet");
            ASSERT_TRUE(sptrColumnsForGet->Type() == CLDEParser::Parsing::Json::JsonValueType::Entity);
            auto sptrColumnsForGetArray = CLDEParser::Parsing::Json::JsonEntityHelper::ToSPtrArray(sptrColumnsForGet->sptrJsonEntity);
            ASSERT_TRUE(sptrColumnsForGetArray->Container().size() == 4);
            auto sptrThirdColumn = *(sptrColumnsForGetArray->Container().cbegin() + 2);
            ASSERT_TRUE(sptrThirdColumn->CopyToString() == "LastName");

            // Version
            auto sptrVersionArray= CLDEParser::Parsing::Json::JsonEntityHelper::ToSPtrArray(sptrRoot->GetValue("Version")->sptrJsonEntity);
            auto sptrVersionIterator = sptrVersionArray->Container().cbegin();
            auto sptrAuthor = CLDEParser::Parsing::Json::JsonEntityHelper::ToSPtrObject((*sptrVersionIterator)->sptrJsonEntity);
            auto sptrVersion = CLDEParser::Parsing::Json::JsonEntityHelper::ToSPtrObject((*(sptrVersionIterator+1))->sptrJsonEntity);
            ASSERT_TRUE(sptrAuthor.operator->());
            ASSERT_TRUE(sptrVersion.operator->());
            auto verMajor = sptrVersion->GetValue("Major")->intValue;
            auto verMinor = sptrVersion->GetValue("Minor")->intValue;
            ASSERT_TRUE(verMajor == 1);
            ASSERT_TRUE(verMinor == 0);
        }
    }
}
#endif //CLDEPARSER_TEST_CASE01_ACTUALEXAMPLES_HPP
