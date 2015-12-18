//
// Created by Duc-Anh LE on 11/21/15.
//

#include "JsonDefaultParser.h"
#include "JsonDerivativeFactory.h"
#include "JsonSyntaxModel.h"

#include <cldeparser/CldeParser.h>

struct CLDEParser::Parsing::Json::JsonDefaultParser::JsonParserImpl {

    Scanner scanner;
    ParserSingle parser;

    JsonParserImpl() : parser(JsonDerivativeFactory::CreateJsonDerivativeInstance()) {
        scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateSpace());
        scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateTab());
        scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateCarriageReturn());
        scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateLineFeed());
        scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateNull());
        scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBoolTrue());
        scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBoolFalse());
        scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateNumberInteger());
        scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateNumber());
        scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateId());
        scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateString());
        scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateColon());
        scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateComma());
        scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateCurlyBraceOpen());
        scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateCurlyBraceClosing());
        scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBracketOpen());
        scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBracketClosing());
    }
};

CLDEParser::Parsing::Json::JsonDefaultParser::JsonDefaultParser() {
    _ptrImpl = new JsonDefaultParser::JsonParserImpl();
}

CLDEParser::Parsing::Json::JsonDefaultParser::JsonDefaultParser(const CLDEParser::Parsing::Json::JsonDefaultParser &jsonParser) : _ptrImpl{jsonParser._ptrImpl} {
    //
}

CLDEParser::Parsing::Json::JsonDefaultParser &CLDEParser::Parsing::Json::JsonDefaultParser::operator=(const CLDEParser::Parsing::Json::JsonDefaultParser &jsonParser) {

    if(&jsonParser != this){
        delete _ptrImpl;
        _ptrImpl = jsonParser._ptrImpl;
    }

    return *this;
}

CLDEParser::Parsing::Json::JsonDefaultParser::~JsonDefaultParser() {
    delete _ptrImpl;
}

CLDEParser::Parsing::Json::SPtrJsonEntity CLDEParser::Parsing::Json::JsonDefaultParser::Parse(std::string const &json) const {

    _ptrImpl->parser.Reset();
    
    // Scanning
    auto tokens = _ptrImpl->scanner.Scan(json);
    auto filteredCodes = Scanning::TokenHelper::DefaultFilterCodes();
    auto filteredTokens = Scanning::TokenHelper::Filter(filteredCodes, tokens);

    // Parsing
    auto sptrSyntaxModel = _ptrImpl->parser.ParseCast<Parsing::Json::JsonSyntaxModel>(filteredTokens);
    auto sptrJsonEntity = sptrSyntaxModel->CreateSPtrJsonEnity();

    return sptrJsonEntity;
}
