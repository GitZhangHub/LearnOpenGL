QMAKE_CXXFLAGS += -std=c++11
TEMPLATE = app
#CONFIG   += plugin
#CONFIG +=staticlib
#        if(!contains(DEFINES,GEOVIS_LIBRARY_STATIC)){
#        }

INCLUDEPATH += \
        $$(OPENGLDIR)/include




CONFIG(release, debug|release){
        PREFLAG=release
        ENDFLAG=''
}

CONFIG(debug, debug|release){
    TARGET = HelloTrangled
        PREFLAG=debug
        ENDFLAG=d
}
TARGET = HelloTrangle$$ENDFLAG
DESTDIR = $$(OPENGLDIR)/bin
OBJECTS_DIR = ./$$PREFLAG
MOC_DIR=./$$PREFLAG/temp
UI_DIR =./$$PREFLAG/temp

win32{
    LIBS += -L$$(OPENGLDIR)/lib  -lglfw3dll$$ENDFLAG
}



macos{
        LIBS += -L$$(OPENGLDIR)/lib -lglfw
        LIBS += -L/Users/apple/workspace/ThirdParty/lib -lgtest
}



SOURCES += \
    ./main.cpp \
    ../../src/glad.c \
    triangle.cpp \
    gtest_all.cpp


HEADERS += \
    ../../include/GLFW/glfw3.h \
    ../../include/glad/glad.h \
    ../../include/learnopengl/shader_s.h \
    ../../include/stb_image.h \
    ../../include/gtest/gtest.h \
    ../../include/learnopengl/OpenGL330AP.h
