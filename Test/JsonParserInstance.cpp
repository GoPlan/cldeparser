//
// Created by LE, Duc Anh on 8/25/15.
//

#include "JsonParserInstance.h"

namespace CLDEParser {
    namespace Test {

        JsonParserInstance::JsonParserInstance()
                : _scanner{}, _parser{Parsing::ParserFactory::CreateJsonDerivative()} {
            //
            init();
        }

        void JsonParserInstance::init() {
            _scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateSpace());
            _scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateTab());
            _scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateNull());
            _scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBoolTrue());
            _scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBoolFalse());
            _scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateNumberInteger());
            _scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateNumber());
            _scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateId());
            _scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateString());
            _scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateColon());
            _scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateComma());
            _scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateCurlyBraceOpen());
            _scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateCurlyBraceClosing());
            _scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBracketOpen());
            _scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBracketClosing());
        }

        Parsing::Json::SPtrJsonEntity JsonParserInstance::Parse(std::string const &json) const {

            // Scanning
            auto tokens = _scanner.Scan(json);
            auto filteredCodes = Scanning::TokenHelper::DefaultFilterCodes();
            auto filteredTokens = Scanning::TokenHelper::Filter(filteredCodes, tokens);

            // Parsing
            auto sptrSyntaxModel = _parser.ParseCast<Parsing::Json::JsonSyntaxModel>(filteredTokens);
            auto sptrJsonEntity = sptrSyntaxModel->CreateSPtrJsonEnity();

            return sptrJsonEntity;
        }
    }
}


