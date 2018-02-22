LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL2

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include $(LOCAL_PATH)/../SDL2_image/ $(LOCAL_PATH)/../SDL2_ttf/ $(LOCAL_PATH)/../KiWi/

# Add your application source files here...
LOCAL_SRC_FILES := main.cpp Team.h Team.cpp JsonInterface.h JsonInterface.cpp Result.h Result.cpp Match.h Match.cpp 53_extensions.cpp GFX_Iface.h GFX_Iface.cpp


LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_ttf KiWi_static

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)
