//
//  CLDEiOSParser.mm
//  cldeparser-ios
//
//  Created by Duc-Anh LE on 11/20/15.
//  Copyright © 2015 Duc-Anh LE. All rights reserved.
//

#import "CLDEiOSParser.hpp"
#import <cldeparser/CldeParser.h>
#import <cldeparser-json/Json.h>
#import <cldeparser-json/JsonDefaultParser.h>

using namespace CLDEParser;

struct Impl {
    
    Parsing::Json::JsonDefaultParser parser;
    
    Parsing::Json::SPtrJsonEntity Parse(std::string const &string){
        return parser.Parse(string);
    }
};

@implementation CLDEiOSParser

- (instancetype)init {
    
    self = [super init];
    
    if(self){
        _ptrImpl = new Impl();
    }
    
    return self;
}

- (void)printJson:(NSString *)jsonString {
    
    try {
        
        auto sptrJsonEntity = _ptrImpl->Parse(std::string([jsonString UTF8String]));
        auto sptrName = sptrJsonEntity->GetValue("name");
        auto sptrAge = sptrJsonEntity->GetValue("age");
        NSLog(@"%s %s", sptrName->CopyToString().c_str(), sptrAge->CopyToString().c_str());
        
    } catch (std::exception& ex) {
        NSLog(@"%s", ex.what());
    }
}

- (NSString *)translateJson:(NSString *)jsonString {
    
    NSMutableString * translation = [[NSMutableString alloc] init];
    
    try {
        
        auto sptrJsonEntity = _ptrImpl->Parse(std::string([jsonString UTF8String]));
        auto sptrName = sptrJsonEntity->GetValue("name");
        auto sptrAge = sptrJsonEntity->GetValue("age");

        [translation appendString:[NSString stringWithUTF8String:sptrName->CopyToString().c_str()]];
        [translation appendString:@" "];
        [translation appendString:[NSString stringWithUTF8String:sptrAge->CopyToString().c_str()]];
        
    } catch (std::exception& ex) {

        [translation appendString:[NSString stringWithUTF8String:ex.what()]];
        
    }
    
    return translation;
}

- (void)dealloc {
    delete _ptrImpl;
}

@end
