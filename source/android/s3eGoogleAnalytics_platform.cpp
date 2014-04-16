/*
 * android-specific implementation of the s3eGoogleAnalytics extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eGoogleAnalytics_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_s3eGoogleAnalytics_Init;
static jmethodID g_s3eGoogleAnalytics_Start;
static jmethodID g_s3eGoogleAnalytics_End;

s3eResult s3eGoogleAnalyticsInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("s3eGoogleAnalytics");
    if (!cls)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_s3eGoogleAnalytics_Init = env->GetMethodID(cls, "s3eGoogleAnalytics_Init", "(Ljava/lang/String;Ljava/lang/String;)I");
    if (!g_s3eGoogleAnalytics_Init)
        goto fail;

    g_s3eGoogleAnalytics_Start = env->GetMethodID(cls, "s3eGoogleAnalytics_Start", "()I");
    if (!g_s3eGoogleAnalytics_Start)
        goto fail;

    g_s3eGoogleAnalytics_End = env->GetMethodID(cls, "s3eGoogleAnalytics_End", "()I");
    if (!g_s3eGoogleAnalytics_End)
        goto fail;



    IwTrace(GOOGLEANALYTICS, ("GOOGLEANALYTICS init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(s3eGoogleAnalytics, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;

}

void s3eGoogleAnalyticsTerminate_platform()
{
    // Add any platform-specific termination code here
}

s3eResult s3eGoogleAnalytics_Init_platform(const char* ua_id, const char* screen_name)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring ua_id_jstr = env->NewStringUTF(ua_id);
    jstring screen_name_jstr = env->NewStringUTF(screen_name);
    return (s3eResult)env->CallIntMethod(g_Obj, g_s3eGoogleAnalytics_Init, ua_id_jstr, screen_name_jstr);
}

s3eResult s3eGoogleAnalytics_Start_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_s3eGoogleAnalytics_Start);
}

s3eResult s3eGoogleAnalytics_End_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_s3eGoogleAnalytics_End);
}
