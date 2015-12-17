/**
 * @author tengfei.li@renren-inc.com
 * @since 15/12/16, 下午6:31
 */

#ifndef NELEM
#define NELEM(x) ((int) (sizeof(x) / sizeof((x)[0])))
#endif