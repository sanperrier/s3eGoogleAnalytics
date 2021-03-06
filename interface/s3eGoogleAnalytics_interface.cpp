/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "s3eGoogleAnalytics.h"


// Define S3E_EXT_SKIP_LOADER_CALL_LOCK on the user-side to skip LoaderCallStart/LoaderCallDone()-entry.
// e.g. in s3eNUI this is used for generic user-side IwUI-based implementation.
#ifndef S3E_EXT_SKIP_LOADER_CALL_LOCK
#if defined I3D_ARCH_MIPS || defined S3E_ANDROID_X86 || (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP)) || defined I3D_ARCH_NACLX86_64
// For platforms missing stack-switching (MIPS, WP8, Android-x86, NaCl, etc.) make loader-entry via LoaderCallStart/LoaderCallDone() on the user-side.
#define LOADER_CALL_LOCK
#endif
#endif

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef       void(*s3eGoogleAnalytics_SetScreenName_t)(const char* screen_name);
typedef       void(*s3eGoogleAnalytics_SetUserID_t)(const char* user_name);
typedef       void(*s3eGoogleAnalytics_SetLogLevel_t)(s3eGoogleAnalyticsLogLevel level);

/**
 * struct that gets filled in by s3eGoogleAnalyticsRegister
 */
typedef struct s3eGoogleAnalyticsFuncs
{
    s3eGoogleAnalytics_SetScreenName_t m_s3eGoogleAnalytics_SetScreenName;
    s3eGoogleAnalytics_SetUserID_t m_s3eGoogleAnalytics_SetUserID;
    s3eGoogleAnalytics_SetLogLevel_t m_s3eGoogleAnalytics_SetLogLevel;
} s3eGoogleAnalyticsFuncs;

static s3eGoogleAnalyticsFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0x95f3a0d5, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: s3eGoogleAnalytics");

        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0x95f3a0d5, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool s3eGoogleAnalyticsAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

void s3eGoogleAnalytics_SetScreenName(const char* screen_name)
{
    IwTrace(GOOGLEANALYTICS_VERBOSE, ("calling s3eGoogleAnalytics[0] func: s3eGoogleAnalytics_SetScreenName"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eGoogleAnalytics_SetScreenName);
#endif

    g_Ext.m_s3eGoogleAnalytics_SetScreenName(screen_name);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eGoogleAnalytics_SetScreenName);
#endif

    return;
}

void s3eGoogleAnalytics_SetUserID(const char* user_name)
{
    IwTrace(GOOGLEANALYTICS_VERBOSE, ("calling s3eGoogleAnalytics[1] func: s3eGoogleAnalytics_SetUserID"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eGoogleAnalytics_SetUserID);
#endif

    g_Ext.m_s3eGoogleAnalytics_SetUserID(user_name);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eGoogleAnalytics_SetUserID);
#endif

    return;
}

void s3eGoogleAnalytics_SetLogLevel(s3eGoogleAnalyticsLogLevel level)
{
    IwTrace(GOOGLEANALYTICS_VERBOSE, ("calling s3eGoogleAnalytics[2] func: s3eGoogleAnalytics_SetLogLevel"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eGoogleAnalytics_SetLogLevel);
#endif

    g_Ext.m_s3eGoogleAnalytics_SetLogLevel(level);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eGoogleAnalytics_SetLogLevel);
#endif

    return;
}
