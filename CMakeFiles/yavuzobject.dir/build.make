# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ufuk/Documents/yavuzWithC++/libchess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ufuk/Documents/yavuzWithC++/libchess

# Include any dependencies generated for this target.
include CMakeFiles/yavuzobject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/yavuzobject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/yavuzobject.dir/flags.make

CMakeFiles/yavuzobject.dir/main.cpp.o: CMakeFiles/yavuzobject.dir/flags.make
CMakeFiles/yavuzobject.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/yavuzobject.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/yavuzobject.dir/main.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/main.cpp

CMakeFiles/yavuzobject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yavuzobject.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/main.cpp > CMakeFiles/yavuzobject.dir/main.cpp.i

CMakeFiles/yavuzobject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yavuzobject.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/main.cpp -o CMakeFiles/yavuzobject.dir/main.cpp.s

# Object files for target yavuzobject
yavuzobject_OBJECTS = \
"CMakeFiles/yavuzobject.dir/main.cpp.o"

# External object files for target yavuzobject
yavuzobject_EXTERNAL_OBJECTS =

yavuzobject: CMakeFiles/yavuzobject.dir/main.cpp.o
yavuzobject: CMakeFiles/yavuzobject.dir/build.make
yavuzobject: CMakeFiles/yavuzobject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable yavuzobject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/yavuzobject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/yavuzobject.dir/build: yavuzobject

.PHONY : CMakeFiles/yavuzobject.dir/build

CMakeFiles/yavuzobject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/yavuzobject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/yavuzobject.dir/clean

CMakeFiles/yavuzobject.dir/depend:
	cd /home/ufuk/Documents/yavuzWithC++/libchess && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ufuk/Documents/yavuzWithC++/libchess /home/ufuk/Documents/yavuzWithC++/libchess /home/ufuk/Documents/yavuzWithC++/libchess /home/ufuk/Documents/yavuzWithC++/libchess /home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles/yavuzobject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/yavuzobject.dir/depend

