/**
 * @author tengfei.li@renren-inc.com
 * @since 15/12/14, 下午3:23
 */
#include <assert.h>
#include <jni.h>
#include <pthread.h>

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfilter.h>

#include "rennlivejni.h"
#include "renn_common_macros.h"
#include "renn_log.h"

static JavaVM *g_jvm;




//FIX
struct URLProtocol;
/**
 * Protocol Support Information
 */
char * urlprotocolinfo(){

    char info[40000]={0};
    av_register_all();

    struct URLProtocol *pup = NULL;
    //Input
    struct URLProtocol **p_temp = &pup;
    avio_enum_protocols((void **)p_temp, 0);
    while ((*p_temp) != NULL){
        sprintf(info, "%s[In ][%10s]\n", info, avio_enum_protocols((void **)p_temp, 0));
    }
    pup = NULL;
    //Output
    avio_enum_protocols((void **)p_temp, 1);
    while ((*p_temp) != NULL){
        sprintf(info, "%s[Out][%10s]\n", info, avio_enum_protocols((void **)p_temp, 1));
    }

    return info;
}

/**
 * AVFormat Support Information
 */
char * avformatinfo(){

    char info[40000] = { 0 };

    av_register_all();

    AVInputFormat *if_temp = av_iformat_next(NULL);
    AVOutputFormat *of_temp = av_oformat_next(NULL);
    //Input
    while(if_temp!=NULL){
        sprintf(info, "%s[In ] %10s\n", info, if_temp->name);
        if_temp=if_temp->next;
    }
    //Output
    while (of_temp != NULL){
        sprintf(info, "%s[Out] %10s\n", info, of_temp->name);
        of_temp = of_temp->next;
    }
    return info;
}

/**
 * AVCodec Support Information
 */
char * avcodecinfo()
{
    char info[40000] = { 0 };

    av_register_all();

    AVCodec *c_temp = av_codec_next(NULL);

    while(c_temp!=NULL){
        if (c_temp->decode!=NULL){
            sprintf(info, "%s[Dec]", info);
        }
        else{
            sprintf(info, "%s[Enc]", info);
        }
        switch (c_temp->type){
            case AVMEDIA_TYPE_VIDEO:
                sprintf(info, "%s[Video]", info);
                break;
            case AVMEDIA_TYPE_AUDIO:
                sprintf(info, "%s[Audio]", info);
                break;
            default:
                sprintf(info, "%s[Other]", info);
                break;
        }

        sprintf(info, "%s %10s\n", info, c_temp->name);

        c_temp=c_temp->next;
    }
    return info;
}

/**
 * AVFilter Support Information
 */
char * avfilterinfo()
{
    char info[40000] = { 0 };
    av_register_all();
    AVFilter *f_temp = (AVFilter *)avfilter_next(NULL);
    while (f_temp != NULL){
        sprintf(info, "%s[%10s]\n", info, f_temp->name);
    }
    return info;
}

/**
 * Configuration Information
 */
char * configurationinfo()
{
    char info[10000] = { 0 };
    av_register_all();

    sprintf(info, "%s\n", avcodec_configuration());

    return info;
}




static void renn_live_native_init(JNIEnv *env)
{
    ALOGE("renn_live_native_init() called");
}

static void renn_live_native_setup(JNIEnv *env, jobject thiz, jobject weak_this)
{
    ALOGE("renn_live_native_setup() called");
}

static void renn_live_native_finalize(JNIEnv *env, jobject thiz, jobject name, jobject value)
{
    ALOGE("renn_live_native_finalize() called");
}


static JNINativeMethod g_methods[] = {
        {"native_init",     "()V",                   (void *) renn_live_native_init},
        {"native_setup",    "(Ljava/lang/Object;)V", (void *) renn_live_native_setup},
        {"native_finalize", "()V",                   (void *) renn_live_native_finalize}
};

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    ALOGE("JNI_OnLoad() called");


    JNIEnv* env = NULL;
    g_jvm = vm;
    if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }
    assert(env != NULL);

    jclass cls = (*env)->FindClass(env, RENN_LIVE_JNI_JAVA_CLASS);

    (*env)->RegisterNatives(env, cls, g_methods, NELEM(g_methods) );

    return JNI_VERSION_1_4;
}

JNIEXPORT void JNI_OnUnload(JavaVM *jvm, void *reserved)
{
    ALOGE("JNI_OnUnload() called");
}