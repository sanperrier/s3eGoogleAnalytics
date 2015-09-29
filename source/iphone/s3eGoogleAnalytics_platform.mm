/*
 * iphone-specific implementation of the s3eGoogleAnalytics extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eGoogleAnalytics_internal.h"
#include "s3eConfig.h"
#import "GAI.h"
#import "GAIDictionaryBuilder.h"
#import "GAIFields.h"

s3eResult s3eGoogleAnalyticsInit_platform()
{
    char* devKey = new char[0xff];
    if (s3eConfigGetString("GoogleAnalytics", "TrackingId", devKey) == S3E_RESULT_ERROR)
    {
        
    }
    
    [GAI sharedInstance].dispatchInterval = 60;
    [GAI sharedInstance].optOut = NO;
    [GAI sharedInstance].trackUncaughtExceptions = YES;
    id tracker = [[GAI sharedInstance] trackerWithTrackingId:[NSString stringWithUTF8String:devKey]];
    
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void s3eGoogleAnalyticsTerminate_platform()
{ 
}

void s3eGoogleAnalytics_SetScreenName_platform(const char* screen_name)
{
    if (screen_name)
    {
        [[[GAI sharedInstance] defaultTracker] set:kGAIScreenName
                                             value:[NSString stringWithUTF8String:screen_name]];
        [[[GAI sharedInstance] defaultTracker] send:[[GAIDictionaryBuilder createScreenView] build]];
    }
}

void s3eGoogleAnalytics_SetUserID_platform(const char* user_name)
{
    if (user_name)
    {
        [[[GAI sharedInstance] defaultTracker] set:kGAIUserId
                                             value:[NSString stringWithUTF8String:user_name]];
    }
}

void s3eGoogleAnalytics_SetLogLevel_platform(s3eGoogleAnalyticsLogLevel level)
{
    [[GAI sharedInstance].logger setLogLevel:(GAILogLevel)level];
}
