QMAKE_CXXFLAGS += -std=c++11
TEMPLATE = app





CONFIG(release, debug|release){
        PREFLAG=release
        ENDFLAG=''
}

CONFIG(debug, debug|release){
        PREFLAG=debug
        ENDFLAG=d
}
TARGET = learnOpenGL$$ENDFLAG
DESTDIR = ../bin
OBJECTS_DIR = ./$$PREFLAG
MOC_DIR=./$$PREFLAG/temp
UI_DIR =./$$PREFLAG/temp

win32{
    LIBS += -L$$(OPENGLDIR)/lib  -lglfw3dll$$ENDFLAG
}



        LIBS += -L../lib -lgtest -lglfw

INCLUDEPATH += \
        ../include

SOURCES += \
    ../src/main.cpp \
    ../src/gtest_all.cpp \
    ../src/glad.c \
    ../src/triangle.cpp \
    ../src/01hellowindow.cpp \
    ../src/commonapi.cpp


HEADERS += \
    ../include/GLFW/glfw3.h \
    ../include/glad/glad.h \
    ../include/learnopengl/shader_s.h \
    ../include/stb_image.h \
    ../include/gtest/gtest.h \
    ../include/learnopengl/OpenGL330AP.h
