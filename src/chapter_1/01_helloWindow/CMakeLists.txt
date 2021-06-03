cmake_minimum_required(VERSION 3.0)
Project(HELLOWINDOW)
# ADD_SUBDIRECTORY(src bin) #(source_dir [binary_dir] [exclude_from_all]) 
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) # the same as pre
MESSAGE(STATUS "this is Binary dir: "  ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "this is Binary dir: "  ${PROJECT_BINARY_DIR})
INCLUDE_DIRECTORIES(/home/holo/testspace/LearnOpenGL/include)
LINK_DIRECTORIES(/home/holo/testspace/LearnOpenGL/lib/ubuntu18.04)

SET(SRC_LIST hellowindow.cpp)
ADD_EXECUTABLE(helloWindow ${SRC_LIST})
target_link_libraries(helloWindow  glfw3 glad_GL GL Xinerama Xxf86vm  X11 Xcursor Xrandr Xi pthread  dl)


#SET(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
