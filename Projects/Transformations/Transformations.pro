QMAKE_CXXFLAGS += -std=c++11
TEMPLATE = app

INCLUDEPATH += \
    += $$(OPENGLDIR)/include




CONFIG(release, debug|release){
    TARGET = Transformations
}
CONFIG(debug, debug|release){
    TARGET = Transformationsd
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



HEADERS +=\
    ../../include/GLFW/glfw3.h \
    ../../include/glad/glad.h \
    ../../include/learnopengl/shader_s.h \
    ../../include/stb_image.h
