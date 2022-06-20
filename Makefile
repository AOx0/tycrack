SYSROOT = $(THEOS)/sdks/MacOSX12.3.sdk
TARGET := macosx:clang:latest:10.15
ARCHS = x86_64 arm64

FINALPACKAGE = 1
DEBUG = 0
THEOS_LEAN_AND_MEAN = 1

LIBRARY_NAME = TyCrack

$(LIBRARY_NAME)_FILES = $(LIBRARY_NAME).c
$(LIBRARY_NAME)_LDFLAGS = -fobjc-arc
$(LIBRARY_NAME)_INSTALL_PATH = .

include $(THEOS)/makefiles/common.mk
include $(THEOS_MAKE_PATH)/library.mk
