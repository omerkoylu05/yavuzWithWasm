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
include CMakeFiles/split.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/split.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/split.dir/flags.make

CMakeFiles/split.dir/examples/split.cpp.o: CMakeFiles/split.dir/flags.make
CMakeFiles/split.dir/examples/split.cpp.o: examples/split.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/split.dir/examples/split.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/split.dir/examples/split.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/examples/split.cpp

CMakeFiles/split.dir/examples/split.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/split.dir/examples/split.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/examples/split.cpp > CMakeFiles/split.dir/examples/split.cpp.i

CMakeFiles/split.dir/examples/split.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/split.dir/examples/split.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/examples/split.cpp -o CMakeFiles/split.dir/examples/split.cpp.s

# Object files for target split
split_OBJECTS = \
"CMakeFiles/split.dir/examples/split.cpp.o"

# External object files for target split
split_EXTERNAL_OBJECTS =

split: CMakeFiles/split.dir/examples/split.cpp.o
split: CMakeFiles/split.dir/build.make
split: static/libchess.a
split: CMakeFiles/split.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable split"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/split.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/split.dir/build: split

.PHONY : CMakeFiles/split.dir/build

CMakeFiles/split.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/split.dir/cmake_clean.cmake
.PHONY : CMakeFiles/split.dir/clean

CMakeFiles/split.dir/depend:
	cd /home/ufuk/Documents/yavuzWithC++/libchess && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ufuk/Documents/yavuzWithC++/libchess /home/ufuk/Documents/yavuzWithC++/libchess /home/ufuk/Documents/yavuzWithC++/libchess /home/ufuk/Documents/yavuzWithC++/libchess /home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles/split.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/split.dir/depend

