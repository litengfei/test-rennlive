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

static void test(){
	avcodec_register_all();
    av_register_all();
	
	AVFormatContext *ic;
	


	ic = avformat_alloc_context();
	if(!ic){
		ALOGE("avformat_alloc_context failed");
		return;
	}


//	ic = 

}

static void tutorial01(){
	av_register_all();
	AVFormatContext *pFormatCtx = NULL;

	if (avformat_open_input(&pFormatCtx, "", NULL, NULL)!=0)
	{
		ALOGE("couldn't open file");
		return;
	}

	if(avformat_find_stream_info(pFormatCtx, NULL)<0){
		ALOGE("couldn't find stream info");
		return;
	}

	int i;
	int videoStream = -1;
	for(i=0; i<pFormatCtx->nb_streams; i++) {
		if(	pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO) {
			videoStream = i;
			break;
		}
	}

	if (videoStream == -1){
		ALOGE("no video stream");
		return;
	}
}


static void renn_live_native_init(JNIEnv *env)
{
    ALOGE("renn_live_native_init() called");
}

static void renn_live_native_setup(JNIEnv *env, jobject thiz, jobject weak_this)
{
	test();
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
