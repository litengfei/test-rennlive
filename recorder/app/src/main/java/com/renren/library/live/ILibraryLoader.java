package com.renren.library.live;

/**
 * So Library Loader Interface
 *
 * @author tengfei.li@renren-inc.com
 * @since 15/12/12, 下午4:59
 */
public interface ILibraryLoader {
    void load(String libName) throws UnsatisfiedLinkError, SecurityException;
}
