package com.renren.library.live;

/**
 * @author tengfei.li@renren-inc.com
 * @since 15/12/12, 下午5:58
 */
public class PlayerLibraryLoader extends BaseVideoLibraryLoader {
    private static ILibraryLoader loader = null;

    synchronized public static void loadOnce() {
        BaseVideoLibraryLoader.loadOnce();
        if (loader == null) {
            loader = newAnonymousLoader();
            loader.load("ijkplayer");
        }
    }
}
