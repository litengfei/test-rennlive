/**
 * @author tengfei.li@renren-inc.com
 * @since 15/12/14, 下午3:23
 */

#include "rennlivejni.h"
#include <jni.h>
#include <pthread.h>

static JNINativeMethod g_methods[] = {
        {"native_init",     "()V",                   (void *) renn_live_native_init},
        {"native_setup",    "(Ljava/lang/Object;)V", (void *) renn_live_native_setup},
        {"native_finalize", "()V",                   (void *) renn_live_native_finalize}
};

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    JNIEnv* env = NULL;

    g_jvm = vm;
    if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }
    assert(env != NULL);

    // FindClass returns LocalReference
    IJK_FIND_JAVA_CLASS(env, g_clazz.clazz, JNI_CLASS_IJKPLAYER);
    (*env)->RegisterNatives(env, g_clazz.clazz, g_methods, NELEM(g_methods) );

    ijkmp_global_init();
    ijkmp_global_set_inject_callback(inject_callback);

    FFmpegApi_global_init(env);

    return JNI_VERSION_1_4;
}

JNIEXPORT void JNI_OnUnload(JavaVM *jvm, void *reserved)
{
}