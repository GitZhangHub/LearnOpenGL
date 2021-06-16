cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(01_helloWindow )
message(STATUS "${PROJECT_NAME} This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "${PROJECT_NAME} This is SOURCE dir " ${PROJECT_SOURCE_DIR})
message(STATUS "3rdparty path:" ${3RDPARTY_PATH})

include_directories(${3RDPARTY_PATH}/include)
include_directories(${INCLUDE_DIR})
link_directories(${3RDPARTY_PATH}/lib)

# FIND_LIBRARY(glfw3)

# add_library(glad
# STATIC
# ../src/glad.c
# )
# link_libraries(glfw)
# link_libraries(glad)
add_executable(01_helloWindow  src/01hellowindow.cpp)
target_link_libraries(01_helloWindow
PUBLIC 
glfw
glad
)

# Prepare RPATH
file(RELATIVE_PATH _rel ${CMAKE_INSTALL_PREFIX}/${INSTALL_BINDIR} ${CMAKE_INSTALL_PREFIX})
if(APPLE)
   set(_rpath "@loader_path/${_rel}")
else()
   set(_rpath "\$ORIGIN/${_rel}")
endif()
file(TO_NATIVE_PATH "${_rpath}/${INSTALL_LIBDIR}" 01_helloWindow_RPATH)


set_target_properties(01_helloWindow
PROPERTIES
MACOSX_RPATH ON
SKIP_BUILD_RPATH OFF
BUILD_WITH_INSTALL_RPATH OFF
INSTALL_RPATH "${01_helloWindow_RPATH}"
INSTALL_RPATH_USE_LINK_PATH ON
)

add_executable(02_helloTriangle  src/02helloTriangle.cpp)
target_link_libraries(02_helloTriangle
PUBLIC 
glfw
glad
)

add_executable(03shaders  src/03shaders.cpp)
target_link_libraries(03shaders
PUBLIC 
glfw
glad
)

add_executable(04textures  src/04textures.cpp)
target_link_libraries(04textures
PUBLIC 
glfw
glad
)
add_executable(3_9GeometryShader  src/3_9GeometryShader.cpp)
target_link_libraries(3_9GeometryShader
PUBLIC 
glfw
glad
)
add_executable(3_10earth  src/3_10earth.cpp)
target_link_libraries(3_10earth
PUBLIC 
glfw
glad
)




install(
  TARGETS
  01_helloWindow
  02_helloTriangle
  03shaders
  04textures
  3_9GeometryShader
  3_10earth
ARCHIVE
    DESTINATION ${INSTALL_LIBDIR}
    COMPONENT lib
RUNTIME
    DESTINATION ${INSTALL_BINDIR}
    COMPONENT bin
LIBRARY
    DESTINATION ${INSTALL_LIBDIR}
    COMPONENT lib
PUBLIC_HEADER
    DESTINATION ${INSTALL_INCLUDEDIR}
    COMPONENT dev
)