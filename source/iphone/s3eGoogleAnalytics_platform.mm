/*
 * iphone-specific implementation of the s3eAppsFlyer extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eGoogleAnalytics_internal.h"

#include "s3eEdk.h"
#include "IwDebug.h"
#include "s3eConfig.h"

#include "../GA_SDK/GAI.h"
#import <UIKit/UIKit.h>

s3eResult s3eGoogleAnalyticsInit_platform() {
//    char appleAppId[S3E_CONFIG_STRING_MAX+8] = {'\0'};
//    if (s3eConfigGetString("GoogleAnalytics", "appleAppId", appleAppId) == S3E_RESULT_ERROR)
//    {
//        
//    }
//    
//    char devKey[S3E_CONFIG_STRING_MAX+8] = {'\0'};
//    if (s3eConfigGetString("GoogleAnalytics", "TrackingId", devKey) == S3E_RESULT_ERROR)
//    {
//        
//    }
//    
//    [GAI sharedInstance].dispatchInterval = -1;
//    [GAI sharedInstance].optOut = YES;
//    [GAI sharedInstance].trackUncaughtExceptions = YES;
//    id tracker = [[GAI sharedInstance] trackerWithTrackingId:[NSString stringWithUTF8String:devKey]];
    
    return S3E_RESULT_SUCCESS;
}

void s3eGoogleAnalyticsTerminate_platform()
{
    // Add any platform-specific termination code here
}

s3eResult s3eGoogleAnalytics_Init_platform(const char* ua_id, const char* screen_name)
{
    [GAI sharedInstance].dispatchInterval = -1;
    [GAI sharedInstance].optOut = YES;
    [GAI sharedInstance].trackUncaughtExceptions = YES;
    id tracker = [[GAI sharedInstance] trackerWithTrackingId:[NSString stringWithUTF8String:ua_id]];

    return S3E_RESULT_SUCCESS;
}

s3eResult s3eGoogleAnalytics_Start_platform()
{

    return S3E_RESULT_SUCCESS;
}

s3eResult s3eGoogleAnalytics_End_platform()
{

    return S3E_RESULT_SUCCESS;
}
