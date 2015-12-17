/**
 * @author tengfei.li@renren-inc.com
 * @since 15/12/14, 下午3:23
 */

#ifndef RECORDER_RENNLIVEJNI_H
#define RECORDER_RENNLIVEJNI_H

#endif //RECORDER_RENNLIVEJNI_H


#define RENN_LIVE_JNI_JAVA_CLASS "com/renren/library/live/RennLiveJni"


#define RENN_FIND_JAVA_CLASS(env__, var__, classsign__) \
    do { \
        jclass clazz = (*env__)->FindClass(env__, classsign__); \
        if (JJK_ExceptionCheck__catchAll(env) || !(clazz)) { \
            ALOGE("FindClass failed: %s", classsign__); \
            return -1; \
        } \
        var__ = (*env__)->NewGlobalRef(env__, clazz); \
        if (JJK_ExceptionCheck__catchAll(env) || !(var__)) { \
            ALOGE("FindClass::NewGlobalRef failed: %s", classsign__); \
            (*env__)->DeleteLocalRef(env__, clazz); \
            return -1; \
        } \
        (*env__)->DeleteLocalRef(env__, clazz); \
    } while(0);
