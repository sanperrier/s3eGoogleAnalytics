s3eGoogleAnalytics
==================

Android's extension for GoogleAnalytics

HOW TO INTEGRATE (WINDOWS PLATFORM):
------------------------------------

1) Have your Marmalade SDK installed on your machine

2) Execute both s3eGoogleAnalytics_android.mkb and s3eGoogleAnalytics_android_java.mkb by simply clicking on them or writting their names in command line

3) Include the "s3eGoogleAnalytics" in your project's mkb file

USAGE
-----

For initialization simply trigger s3eGoogleAnalytics_Init(const char* ua_id, const char* screen_name) where:
- ua_id - your tracking id from your GoogleAnalytics account
- screen_name - your Screen Name [1], most commonly on mobile your game's package name, like for example:  com.companyname.mygame

To start a new session simply use s3eGoogleAnalytics_Start() and to end it use s3eGoogleAnalytics_End()

[1] https://developers.google.com/analytics/devguides/collection/android/v3/screens
