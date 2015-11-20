//
//  CLDEiOSParser.mm
//  cldeparser-ios
//
//  Created by Duc-Anh LE on 11/20/15.
//  Copyright © 2015 Duc-Anh LE. All rights reserved.
//

#import "CLDEiOSParser.h"
#import <cldeparser/CldeParser.h>
#import <cldeparser-json/Json.h>

using namespace CLDEParser;

struct Impl {
    
    Scanner scanner;
    ParserSingle parser;
    
    Impl() : scanner{}, parser{Parsing::JsonParserFactory::CreateJsonDerivativeInstance()} {
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
    
    Parsing::Json::SPtrJsonEntity Parse(std::string const &json) const {
        
        // Scanning
        auto tokens = scanner.Scan(json);
        auto filteredCodes = Scanning::TokenHelper::DefaultFilterCodes();
        auto filteredTokens = Scanning::TokenHelper::Filter(filteredCodes, tokens);
        
        // Parsing
        auto sptrSyntaxModel = parser.ParseCast<Parsing::Json::JsonSyntaxModel>(filteredTokens);
        auto sptrJsonEntity = sptrSyntaxModel->CreateSPtrJsonEnity();
        
        return sptrJsonEntity;
    }
};

@implementation CLDEiOSParser

- (instancetype)init {
    
    self = [super init];
    
    if(self){
        _uptrImpl.reset(new Impl());
    }
    
    return self;
}

@end
