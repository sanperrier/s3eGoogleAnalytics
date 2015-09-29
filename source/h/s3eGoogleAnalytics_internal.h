/*
 * Internal header for the s3eGoogleAnalytics extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef S3EGOOGLEANALYTICS_INTERNAL_H
#define S3EGOOGLEANALYTICS_INTERNAL_H

#include "s3eTypes.h"
#include "s3eGoogleAnalytics.h"
#include "s3eGoogleAnalytics_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult s3eGoogleAnalyticsInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult s3eGoogleAnalyticsInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void s3eGoogleAnalyticsTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void s3eGoogleAnalyticsTerminate_platform();
void s3eGoogleAnalytics_SetScreenName_platform(const char* screen_name);

void s3eGoogleAnalytics_SetUserID_platform(const char* user_name);

void s3eGoogleAnalytics_SetLogLevel_platform(s3eGoogleAnalyticsLogLevel level);


#endif /* !S3EGOOGLEANALYTICS_INTERNAL_H */