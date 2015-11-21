//
//  CLDEiOSParser.h
//  cldeparser-ios
//
//  Created by Duc-Anh LE on 11/20/15.
//  Copyright © 2015 Duc-Anh LE. All rights reserved.
//

#import <Foundation/Foundation.h>

struct Impl;

@interface CLDEiOSParser : NSObject {
    struct Impl * _ptrImpl;
}

-(void)printJson:(NSString*)jsonString;

@end
