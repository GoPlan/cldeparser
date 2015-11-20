//
//  CLDEiOSParser.h
//  cldeparser-ios
//
//  Created by Duc-Anh LE on 11/20/15.
//  Copyright © 2015 Duc-Anh LE. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <memory>

struct Impl;

@interface CLDEiOSParser : NSObject {
    std::unique_ptr<Impl> _uptrImpl;
}

@end
