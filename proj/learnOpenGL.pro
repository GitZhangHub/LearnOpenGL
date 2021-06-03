QMAKE_CXXFLAGS += -std=c++11
TEMPLATE = app
#QMAKE_MAC_SDK = macosx10.14

# for stb_image ： this  can be defined only once.
#DEFINES +=  STB_IMAGE_IMPLEMENTATION

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





INCLUDEPATH += \
        ../include

SOURCES += \
    ../src/main.cpp \
    ../src/gtest_all.cpp \
    ../src/glad.c \
    ../src/commonapi.cpp \
    ../src/01hellowindow.cpp \
   ../src/02helloTriangle.cpp \
    ../src/03shaders.cpp \
    ../src/04textures.cpp \
    ../src/05translation.cpp \
    ../src/06coordinatesystems.cpp \
    ../src/07camera.cpp

#    ../src/otherTest.cpp \
HEADERS += \
    ../include/GLFW/glfw3.h \
    ../include/glad/glad.h \
    ../include/learnopengl/shader_s.h \
    ../include/stb_image.h \
    ../include/gtest/gtest.h \
    ../include/learnopengl/OpenGL330AP.h
#    ../include/learnopengl/stbimage.h

LIBS += -L../lib -lgtest -lglfw
