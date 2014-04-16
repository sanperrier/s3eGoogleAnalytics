/*
java implementation of the s3eGoogleAnalytics extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import com.ideaworks3d.marmalade.LoaderAPI;
import com.ideaworks3d.marmalade.LoaderActivity;

import com.google.analytics.tracking.android.Fields;
import com.google.analytics.tracking.android.GoogleAnalytics;
import com.google.analytics.tracking.android.MapBuilder;
import com.google.analytics.tracking.android.Tracker;
import com.google.analytics.tracking.android.GAServiceManager;

class s3eGoogleAnalytics
{
	private Tracker tracker;

    public int s3eGoogleAnalytics_Init(String ua_id, String screenName)
    {
		tracker = GoogleAnalytics.getInstance(LoaderActivity.m_Activity).getTracker(ua_id);
		tracker.set(Fields.SCREEN_NAME, screenName);

		GAServiceManager.getInstance().setLocalDispatchPeriod(5);
		
		return 0;
    }
    public int s3eGoogleAnalytics_Start()
    {
		tracker.send(MapBuilder.createAppView().set(Fields.SESSION_CONTROL, "start").build());
        return 0;
    }
    public int s3eGoogleAnalytics_End()
    {
	    tracker.send(MapBuilder.createAppView().set(Fields.SESSION_CONTROL, "end").build());
        return 0;
    }
}
