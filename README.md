s3eGoogleAnalytics
==================

Extension for GoogleAnalytics for Android

* Integration (on Windows machine):

1) Have your Marmalade SDK installed
2) Execute both s3eGoogleAnalytics_android.mkb and s3eGoogleAnalytics_android_java.mkb by simply clicking on them or writting their names in cmd
3) Include the s3eGoogleAnalytics in your project's mkb file

* Usage in code

To initialise it simply trigger s3eGoogleAnalytics_Init(const char* ua_id, const char* screen_name) where:
- ua_id - your tracking id from your GoogleAnalytics account
- screen_name - your Screen name, most commonly on Android mobile your game's package name com.companyname.mysupergame

To start a new session simply use s3eGoogleAnalytics_Start()

Similarly use s3eGoogleAnalytics_End() to end the session 