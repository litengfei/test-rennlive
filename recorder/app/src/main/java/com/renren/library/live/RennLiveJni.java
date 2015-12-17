package com.renren.library.live;

/**
 * @author tengfei.li@renren-inc.com
 * @since 15/12/14, 下午3:23
 */
public class RennLiveJni {

    static {
        System.loadLibrary("rennlive");
    }

    private static native void native_init();

    private static native void native_setup(Object obj);

    private static native void native_finalize();

    public static void test(){
        native_init();
        native_setup(null);
        native_finalize();
    }
}
