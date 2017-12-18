QMAKE_CXXFLAGS += -std=c++11
TEMPLATE = app
#CONFIG   += plugin
#CONFIG +=staticlib
#        if(!contains(DEFINES,GEOVIS_LIBRARY_STATIC)){
#        }

INCLUDEPATH += \
    += $$(OPENGLDIR)/include




CONFIG(release, debug|release){
    TARGET = HelloTrangle
}
CONFIG(debug, debug|release){
    TARGET = HelloTrangled
}

win32{
    DESTDIR = $$(OPENGLDIR)/bin
CONFIG(debug, debug|release){
    LIBS += -L$$(OPENGLDIR)/lib  -lglfw3dlld

}
    CONFIG(release, debug|release){
    LIBS += -L$$(OPENGLDIR)/lib/  -lglfw3dll
}
}


unix{
    DESTDIR = $$(OPENGLDIR)/bin
    CONFIG(debug, debug|release){
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
    ../../../src/glad.c


HEADERS += \
    ../../../include/GLFW/glfw3.h \
    ../../../include/glad/glad.h \
    ../../../include/learnopengl/shader_s.h \
    ../../../include/stb_image.h
