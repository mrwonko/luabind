#   Luabind Android NDK Makefile
#
# A static library module called luabind, which you can add to your project's makefile like this:
#
# LOCAL_STATIC_LIBRARIES := luabind lua
#
# (Substitute lua for the name you gave your lua module.)
#
# Don't forget to enable RTTI and Exceptions:
#
# LOCAL_CPP_FEATURES := exceptions rtti
#
# You need to enable a C++11 compatible toolchain and the STL in your Application.mk:
#
# NDK_TOOLCHAIN_VERSION := 4.8
# APP_STL := gnustl_static

#   Configuration variables
#
# >> Adjust these as necessary! <<

# Lua include directory
MY_LUA_INCLUDE_DIRECTORY := $(call my-dir)/../lua/src

# Name of the lua module
MY_LUA_MODULE := lua


# The below should need no further configuration

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

# Module Name
LOCAL_MODULE    := luabind

# enable C++ Exceptions and rtti
LOCAL_CPP_FEATURES := exceptions rtti

#   Include directories
#
# >> adjust this to point to your local lua sources/includes <<
LOCAL_C_INCLUDES := $(MY_LUA_INCLUDE_DIRECTORY)

# enable C++11
LOCAL_CFLAGS := -std=c++11

LOCAL_SRC_FILES := src/class.cpp \
	src/class_info.cpp \
	src/class_registry.cpp \
	src/class_rep.cpp \
	src/create_class.cpp \
	src/error.cpp \
	src/exception_handler.cpp \
	src/function.cpp \
	src/function_introspection.cpp \
	src/inheritance.cpp \
	src/link_compatibility.cpp \
	src/object_rep.cpp \
	src/open.cpp \
	src/operator.cpp \
	src/pcall.cpp \
	src/scope.cpp \
	src/set_package_preload.cpp \
	src/stack_content_by_name.cpp \
	src/weak_ref.cpp \
	src/wrapper_base.cpp

# Depends on the lua module
LOCAL_STATIC_LIBRARIES := $(MY_LUA_MODULE)

# Build a static library using the LOCAL_*** settings
include $(BUILD_STATIC_LIBRARY)
