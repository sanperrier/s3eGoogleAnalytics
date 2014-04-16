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

s3eResult s3eGoogleAnalytics_Init(const char* ua_id, const char* screen_name)
{
	return s3eGoogleAnalytics_Init_platform(ua_id, screen_name);
}

s3eResult s3eGoogleAnalytics_Start()
{
	return s3eGoogleAnalytics_Start_platform();
}

s3eResult s3eGoogleAnalytics_End()
{
	return s3eGoogleAnalytics_End_platform();
}
