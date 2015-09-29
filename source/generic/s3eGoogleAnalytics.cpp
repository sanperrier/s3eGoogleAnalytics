/*
Generic implementation of the s3eGoogleAnalytics extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "s3eGoogleAnalytics_internal.h"
s3eResult s3eGoogleAnalyticsInit()
{
    //Add any generic initialisation code here
    return s3eGoogleAnalyticsInit_platform();
}

void s3eGoogleAnalyticsTerminate()
{
    //Add any generic termination code here
    s3eGoogleAnalyticsTerminate_platform();
}

void s3eGoogleAnalytics_SetScreenName(const char* screen_name)
{
	s3eGoogleAnalytics_SetScreenName_platform(screen_name);
}

void s3eGoogleAnalytics_SetUserID(const char* user_name)
{
	s3eGoogleAnalytics_SetUserID_platform(user_name);
}

void s3eGoogleAnalytics_SetLogLevel(s3eGoogleAnalyticsLogLevel level)
{
	s3eGoogleAnalytics_SetLogLevel_platform(level);
}
