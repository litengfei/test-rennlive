/**
 * @author tengfei.li@renren-inc.com
 * @since 15/12/16, 下午7:01
 */

#ifndef RENN__LOG_H
#define RENN__LOG_H

#include <stdio.h>

#ifdef __ANDROID__
    #include <android/log.h>
    #define RENN_LOG_UNKNOWN     ANDROID_LOG_UNKNOWN
    #define RENN_LOG_DEFAULT     ANDROID_LOG_DEFAULT

    #define RENN_LOG_VERBOSE     ANDROID_LOG_VERBOSE
    #define RENN_LOG_DEBUG       ANDROID_LOG_DEBUG
    #define RENN_LOG_INFO        ANDROID_LOG_INFO
    #define RENN_LOG_WARN        ANDROID_LOG_WARN
    #define RENN_LOG_ERROR       ANDROID_LOG_ERROR
    #define RENN_LOG_FATAL       ANDROID_LOG_FATAL
    #define RENN_LOG_SILENT      ANDROID_LOG_SILENT

    #define ALOG(level, TAG, ...)    ((void)__android_log_print(level, TAG, __VA_ARGS__))
#else
    #define RENN_LOG_UNKNOWN     0
    #define RENN_LOG_DEFAULT     1

    #define RENN_LOG_VERBOSE     2
    #define RENN_LOG_DEBUG       3
    #define RENN_LOG_INFO        4
    #define RENN_LOG_WARN        5
    #define RENN_LOG_ERROR       6
    #define RENN_LOG_FATAL       7
    #define RENN_LOG_SILENT      8
    #define ALOG(level, TAG, ...)    ((void)printf(__VA_ARGS__))
#endif

#define RENN_LOG_TAG "RENNLIVE"

#define ALOGV(...)  ALOG(RENN_LOG_VERBOSE,   RENN_LOG_TAG, __VA_ARGS__)
#define ALOGD(...)  ALOG(RENN_LOG_DEBUG,     RENN_LOG_TAG, __VA_ARGS__)
#define ALOGI(...)  ALOG(RENN_LOG_INFO,      RENN_LOG_TAG, __VA_ARGS__)
#define ALOGW(...)  ALOG(RENN_LOG_WARN,      RENN_LOG_TAG, __VA_ARGS__)
#define ALOGE(...)  ALOG(RENN_LOG_ERROR,     RENN_LOG_TAG, __VA_ARGS__)
#define LOG_ALWAYS_FATAL(...)   do { ALOGE(__VA_ARGS__); exit(1); } while (0)

#endif
