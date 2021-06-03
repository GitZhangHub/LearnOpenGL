cmake_minimum_required(VERSION 3.0)
Project(GLAD_GL)
# ADD_SUBDIRECTORY(src bin) #(source_dir [binary_dir] [exclude_from_all]) 
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) # the same as pre
MESSAGE(STATUS "this is Binary dir: "  ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "this is Binary dir: "  ${PROJECT_BINARY_DIR})
INCLUDE_DIRECTORIES(/home/holo/testspace/LearnOpenGL/include)
LINK_DIRECTORIES(/home/holo/testspace/LearnOpenGL/lib/ubuntu18.04)

set(SRC_LIST  glad.c)
add_library(glad_GL  ${SRC_LIST})
set(BUILD_SHARED_LIBS ON)
target_link_libraries(glad_GL)


#SET(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
