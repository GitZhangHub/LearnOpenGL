QMAKE_CXXFLAGS += -std=c++11
TEMPLATE = app
#CONFIG   += plugin
#CONFIG +=staticlib
#        if(!contains(DEFINES,GEOVIS_LIBRARY_STATIC)){
#        }
INCLUDEPATH += \
    += $$(GVSDKDIR)/../dependencies/pepper_49/include \
    += $$(OPENGLDIR)/include




CONFIG(release, debug|release){
    TARGET = textures
}
CONFIG(debug, debug|release){
    TARGET = texturesd
}

win32{
CONFIG(release, debug|release){

}
CONFIG(debug, debug|release){

}
}

unix{
    DESTDIR = $$(OPENGLDIR)/bin
    CONFIG(debug, debug|release){
        LIBS += -L$$(GVSDKDIR)/../dependencies/lib/linux_x64 -lppapi_gles2 -lcef -lcef_dll_wrapper
        LIBS += -L$$(OPENGLDIR)/lib -lglfw3d
        LIBS += -lX11  -lXcursor -lXrandr -lXinerama -lXxf86vm -ldl


    }

    CONFIG(release, debug|release){
        LIBS += -L$$(OPENGLDIR)/lib -lglfw3
        LIBS += -lX11  -lXcursor -lXrandr -lXinerama -lXxf86vm -ldl

    }

}



SOURCES += \
    ./main.cpp \
    ../../../src/glad.c \
#    stb_image.cpp


HEADERS +=\
    ../../../include/GLFW/glfw3.h \
    ../../../include/glad/glad.h \
    ../../../include/learnopengl/shader_s.h \
    ../../../include/stb_image.h
