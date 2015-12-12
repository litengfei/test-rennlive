package com.renren.library.live;

/**
 * @author tengfei.li@renren-inc.com
 * @since 15/12/12, 下午5:09
 */
public class BaseVideoLibraryLoader {
    private static ILibraryLoader loader = null;

    synchronized static void loadOnce() {
        if (loader == null) {
            loader = newAnonymousLoader();
            loader.load("ijkffmpeg");
            loader.load("ijksdl");
        }
    }

    protected static ILibraryLoader newAnonymousLoader() {
        return new ILibraryLoader() {
            @Override
            public void load(String libName) throws UnsatisfiedLinkError, SecurityException {
                System.loadLibrary(libName);
            }
        };
    }
}
