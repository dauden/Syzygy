//
//  SyzygyConditionals.h
//  Syzygy
//
//  Created by Dave DeLong on 4/16/18.
//  Copyright © 2018 Syzygy. All rights reserved.
//

// from http://sealiesoftware.com/blog/archive/2010/8/16/TargetConditionalsh.html

#import <Foundation/Foundation.h>
#import <TargetConditionals.h>

// Desktop vs Mobile
#define BUILDING_FOR_DESKTOP (TARGET_OS_OSX)
#define BUILDING_FOR_MOBILE (TARGET_OS_IPHONE)

// Device vs Simulator
#define BUILDING_FOR_DEVICE (TARGET_OS_EMBEDDED || BUILDING_FOR_DESKTOP)
#define BUILDING_FOR_SIMULATOR (TARGET_OS_SIMULATOR)

// App vs Extension
#define BUILDING_AS_EXTENSION 0 // TODO: Figure out something better here
#define BUILDING_AS_APP (!BUILDING_AS_EXTENSION)

#define BUILDING_FOR_DESKTOP_APP (BUILDING_FOR_DESKTOP && BUILDING_AS_APP)
#define BUILDING_FOR_DESKTOP_EXTENSION (BUILDING_FOR_DESKTOP && BUILDING_AS_EXTENSION)

#define BUILDING_FOR_MOBILE_APP (BUILDING_FOR_MOBILE && BUILDING_AS_APP)
#define BUILDING_FOR_MOBILE_EXTENSION (BUILDING_FOR_MOBILE && BUILDING_AS_EXTENSION)

// Various mobile platforms
#define BUILDING_FOR_MAC (BUILDING_FOR_DESKTOP)
#define BUILDING_FOR_IOS (TARGET_OS_IOS)
#define BUILDING_FOR_TV (TARGET_OS_TV)
#define BUILDING_FOR_WATCH (TARGET_OS_WATCH)

#define BUILDING_FOR_MOBILE_DEVICE (BUILDING_FOR_MOBILE && BUILDING_FOR_DEVICE)
#define BUILDING_FOR_MOBILE_SIMULATOR (BUILDING_FOR_MOBILE && BUILDING_FOR_SIMULATOR)

#define BUILDING_FOR_IOS_DEVICE (BUILDING_FOR_IOS && BUILDING_FOR_MOBILE_DEVICE)
#define BUILDING_FOR_IOS_SIMULATOR (BUILDING_FOR_IOS && BUILDING_FOR_MOBILE_SIMULATOR)

#define BUILDING_FOR_WATCH_DEVICE (BUILDING_FOR_WATCH && BUILDING_FOR_MOBILE_DEVICE)
#define BUILDING_FOR_WATCH_SIMULATOR (BUILDING_FOR_WATCH && BUILDING_FOR_MOBILE_SIMULATOR)

#define BUILDING_FOR_TV_DEVICE (BUILDING_FOR_TV && BUILDING_FOR_MOBILE_DEVICE)
#define BUILDING_FOR_TV_SIMULATOR (BUILDING_FOR_TV && BUILDING_FOR_MOBILE_SIMULATOR)
