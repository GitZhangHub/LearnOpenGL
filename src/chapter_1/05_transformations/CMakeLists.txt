cmake_minimum_required(VERSION 2.8)
Project(TEXTURES)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) # the same as pre

INCLUDE_DIRECTORIES(/home/holo/testspace/LearnOpenGL/include)
LINK_DIRECTORIES(/home/holo/testspace/LearnOpenGL/lib/ubuntu18.04)

SET(SRC_LIST transformations.cpp)
ADD_EXECUTABLE(Transformations ${SRC_LIST})
target_link_libraries(Transformations  glfw3 glad_GL GL Xinerama Xxf86vm  X11 Xcursor Xrandr Xi pthread  dl)

