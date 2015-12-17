# @author tengfei.li@renren-inc.com
# @since 15/12/14, 上午8:20

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
# -mfloat-abi=soft is a workaround for FP register corruption on Exynos 4210
# http://www.spinics.net/lists/arm-kernel/msg368417.html
ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
LOCAL_CFLAGS += -mfloat-abi=soft
endif
LOCAL_CFLAGS += -std=c99
LOCAL_LDLIBS += -llog -landroid

LOCAL_C_INCLUDES += $(LOCAL_PATH)
LOCAL_C_INCLUDES += $(MY_APP_FFMPEG_INCLUDE_PATH)

LOCAL_SRC_FILES += rennlivejni.c
LOCAL_SRC_FILES += rennrecorder.c
LOCAL_SRC_FILES += renndebug.c

LOCAL_SHARED_LIBRARIES := ijkffmpeg ijksdl

LOCAL_MODULE := rennlive
include $(BUILD_SHARED_LIBRARY)
