# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/holo/workspace/holo_builder/output/bin/cmake

# The command to remove a file.
RM = /home/holo/workspace/holo_builder/output/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/holo/testspace/LearnOpenGL/src/chapter_1/07_camera

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/holo/testspace/LearnOpenGL/src/chapter_1/07_camera/build

# Include any dependencies generated for this target.
include CMakeFiles/camera.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/camera.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/camera.dir/flags.make

CMakeFiles/camera.dir/camera.cpp.o: CMakeFiles/camera.dir/flags.make
CMakeFiles/camera.dir/camera.cpp.o: ../camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/holo/testspace/LearnOpenGL/src/chapter_1/07_camera/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/camera.dir/camera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/camera.dir/camera.cpp.o -c /home/holo/testspace/LearnOpenGL/src/chapter_1/07_camera/camera.cpp

CMakeFiles/camera.dir/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/camera.dir/camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/holo/testspace/LearnOpenGL/src/chapter_1/07_camera/camera.cpp > CMakeFiles/camera.dir/camera.cpp.i

CMakeFiles/camera.dir/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/camera.dir/camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/holo/testspace/LearnOpenGL/src/chapter_1/07_camera/camera.cpp -o CMakeFiles/camera.dir/camera.cpp.s

# Object files for target camera
camera_OBJECTS = \
"CMakeFiles/camera.dir/camera.cpp.o"

# External object files for target camera
camera_EXTERNAL_OBJECTS =

bin/camera: CMakeFiles/camera.dir/camera.cpp.o
bin/camera: CMakeFiles/camera.dir/build.make
bin/camera: CMakeFiles/camera.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/holo/testspace/LearnOpenGL/src/chapter_1/07_camera/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/camera"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/camera.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/camera.dir/build: bin/camera

.PHONY : CMakeFiles/camera.dir/build

CMakeFiles/camera.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/camera.dir/cmake_clean.cmake
.PHONY : CMakeFiles/camera.dir/clean

CMakeFiles/camera.dir/depend:
	cd /home/holo/testspace/LearnOpenGL/src/chapter_1/07_camera/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/holo/testspace/LearnOpenGL/src/chapter_1/07_camera /home/holo/testspace/LearnOpenGL/src/chapter_1/07_camera /home/holo/testspace/LearnOpenGL/src/chapter_1/07_camera/build /home/holo/testspace/LearnOpenGL/src/chapter_1/07_camera/build /home/holo/testspace/LearnOpenGL/src/chapter_1/07_camera/build/CMakeFiles/camera.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/camera.dir/depend
