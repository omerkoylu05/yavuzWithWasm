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
include CMakeFiles/libchess-shared.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libchess-shared.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libchess-shared.dir/flags.make

CMakeFiles/libchess-shared.dir/src/attackers.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/attackers.cpp.o: src/attackers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libchess-shared.dir/src/attackers.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/attackers.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/attackers.cpp

CMakeFiles/libchess-shared.dir/src/attackers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/attackers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/attackers.cpp > CMakeFiles/libchess-shared.dir/src/attackers.cpp.i

CMakeFiles/libchess-shared.dir/src/attackers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/attackers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/attackers.cpp -o CMakeFiles/libchess-shared.dir/src/attackers.cpp.s

CMakeFiles/libchess-shared.dir/src/checkers.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/checkers.cpp.o: src/checkers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/libchess-shared.dir/src/checkers.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/checkers.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/checkers.cpp

CMakeFiles/libchess-shared.dir/src/checkers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/checkers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/checkers.cpp > CMakeFiles/libchess-shared.dir/src/checkers.cpp.i

CMakeFiles/libchess-shared.dir/src/checkers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/checkers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/checkers.cpp -o CMakeFiles/libchess-shared.dir/src/checkers.cpp.s

CMakeFiles/libchess-shared.dir/src/check_evasions.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/check_evasions.cpp.o: src/check_evasions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/libchess-shared.dir/src/check_evasions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/check_evasions.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/check_evasions.cpp

CMakeFiles/libchess-shared.dir/src/check_evasions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/check_evasions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/check_evasions.cpp > CMakeFiles/libchess-shared.dir/src/check_evasions.cpp.i

CMakeFiles/libchess-shared.dir/src/check_evasions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/check_evasions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/check_evasions.cpp -o CMakeFiles/libchess-shared.dir/src/check_evasions.cpp.s

CMakeFiles/libchess-shared.dir/src/count_moves.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/count_moves.cpp.o: src/count_moves.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/libchess-shared.dir/src/count_moves.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/count_moves.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/count_moves.cpp

CMakeFiles/libchess-shared.dir/src/count_moves.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/count_moves.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/count_moves.cpp > CMakeFiles/libchess-shared.dir/src/count_moves.cpp.i

CMakeFiles/libchess-shared.dir/src/count_moves.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/count_moves.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/count_moves.cpp -o CMakeFiles/libchess-shared.dir/src/count_moves.cpp.s

CMakeFiles/libchess-shared.dir/src/get_fen.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/get_fen.cpp.o: src/get_fen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/libchess-shared.dir/src/get_fen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/get_fen.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/get_fen.cpp

CMakeFiles/libchess-shared.dir/src/get_fen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/get_fen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/get_fen.cpp > CMakeFiles/libchess-shared.dir/src/get_fen.cpp.i

CMakeFiles/libchess-shared.dir/src/get_fen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/get_fen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/get_fen.cpp -o CMakeFiles/libchess-shared.dir/src/get_fen.cpp.s

CMakeFiles/libchess-shared.dir/src/is_legal.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/is_legal.cpp.o: src/is_legal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/libchess-shared.dir/src/is_legal.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/is_legal.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/is_legal.cpp

CMakeFiles/libchess-shared.dir/src/is_legal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/is_legal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/is_legal.cpp > CMakeFiles/libchess-shared.dir/src/is_legal.cpp.i

CMakeFiles/libchess-shared.dir/src/is_legal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/is_legal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/is_legal.cpp -o CMakeFiles/libchess-shared.dir/src/is_legal.cpp.s

CMakeFiles/libchess-shared.dir/src/king_allowed.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/king_allowed.cpp.o: src/king_allowed.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/libchess-shared.dir/src/king_allowed.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/king_allowed.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/king_allowed.cpp

CMakeFiles/libchess-shared.dir/src/king_allowed.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/king_allowed.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/king_allowed.cpp > CMakeFiles/libchess-shared.dir/src/king_allowed.cpp.i

CMakeFiles/libchess-shared.dir/src/king_allowed.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/king_allowed.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/king_allowed.cpp -o CMakeFiles/libchess-shared.dir/src/king_allowed.cpp.s

CMakeFiles/libchess-shared.dir/src/legal_captures.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/legal_captures.cpp.o: src/legal_captures.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/libchess-shared.dir/src/legal_captures.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/legal_captures.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/legal_captures.cpp

CMakeFiles/libchess-shared.dir/src/legal_captures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/legal_captures.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/legal_captures.cpp > CMakeFiles/libchess-shared.dir/src/legal_captures.cpp.i

CMakeFiles/libchess-shared.dir/src/legal_captures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/legal_captures.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/legal_captures.cpp -o CMakeFiles/libchess-shared.dir/src/legal_captures.cpp.s

CMakeFiles/libchess-shared.dir/src/legal_moves.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/legal_moves.cpp.o: src/legal_moves.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/libchess-shared.dir/src/legal_moves.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/legal_moves.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/legal_moves.cpp

CMakeFiles/libchess-shared.dir/src/legal_moves.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/legal_moves.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/legal_moves.cpp > CMakeFiles/libchess-shared.dir/src/legal_moves.cpp.i

CMakeFiles/libchess-shared.dir/src/legal_moves.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/legal_moves.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/legal_moves.cpp -o CMakeFiles/libchess-shared.dir/src/legal_moves.cpp.s

CMakeFiles/libchess-shared.dir/src/legal_noncaptures.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/legal_noncaptures.cpp.o: src/legal_noncaptures.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/libchess-shared.dir/src/legal_noncaptures.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/legal_noncaptures.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/legal_noncaptures.cpp

CMakeFiles/libchess-shared.dir/src/legal_noncaptures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/legal_noncaptures.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/legal_noncaptures.cpp > CMakeFiles/libchess-shared.dir/src/legal_noncaptures.cpp.i

CMakeFiles/libchess-shared.dir/src/legal_noncaptures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/legal_noncaptures.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/legal_noncaptures.cpp -o CMakeFiles/libchess-shared.dir/src/legal_noncaptures.cpp.s

CMakeFiles/libchess-shared.dir/src/makemove.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/makemove.cpp.o: src/makemove.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/libchess-shared.dir/src/makemove.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/makemove.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/makemove.cpp

CMakeFiles/libchess-shared.dir/src/makemove.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/makemove.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/makemove.cpp > CMakeFiles/libchess-shared.dir/src/makemove.cpp.i

CMakeFiles/libchess-shared.dir/src/makemove.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/makemove.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/makemove.cpp -o CMakeFiles/libchess-shared.dir/src/makemove.cpp.s

CMakeFiles/libchess-shared.dir/src/movegen.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/movegen.cpp.o: src/movegen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/libchess-shared.dir/src/movegen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/movegen.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/movegen.cpp

CMakeFiles/libchess-shared.dir/src/movegen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/movegen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/movegen.cpp > CMakeFiles/libchess-shared.dir/src/movegen.cpp.i

CMakeFiles/libchess-shared.dir/src/movegen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/movegen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/movegen.cpp -o CMakeFiles/libchess-shared.dir/src/movegen.cpp.s

CMakeFiles/libchess-shared.dir/src/perft.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/perft.cpp.o: src/perft.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/libchess-shared.dir/src/perft.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/perft.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/perft.cpp

CMakeFiles/libchess-shared.dir/src/perft.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/perft.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/perft.cpp > CMakeFiles/libchess-shared.dir/src/perft.cpp.i

CMakeFiles/libchess-shared.dir/src/perft.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/perft.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/perft.cpp -o CMakeFiles/libchess-shared.dir/src/perft.cpp.s

CMakeFiles/libchess-shared.dir/src/pinned.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/pinned.cpp.o: src/pinned.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/libchess-shared.dir/src/pinned.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/pinned.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/pinned.cpp

CMakeFiles/libchess-shared.dir/src/pinned.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/pinned.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/pinned.cpp > CMakeFiles/libchess-shared.dir/src/pinned.cpp.i

CMakeFiles/libchess-shared.dir/src/pinned.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/pinned.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/pinned.cpp -o CMakeFiles/libchess-shared.dir/src/pinned.cpp.s

CMakeFiles/libchess-shared.dir/src/predict_hash.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/predict_hash.cpp.o: src/predict_hash.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/libchess-shared.dir/src/predict_hash.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/predict_hash.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/predict_hash.cpp

CMakeFiles/libchess-shared.dir/src/predict_hash.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/predict_hash.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/predict_hash.cpp > CMakeFiles/libchess-shared.dir/src/predict_hash.cpp.i

CMakeFiles/libchess-shared.dir/src/predict_hash.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/predict_hash.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/predict_hash.cpp -o CMakeFiles/libchess-shared.dir/src/predict_hash.cpp.s

CMakeFiles/libchess-shared.dir/src/set_fen.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/set_fen.cpp.o: src/set_fen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/libchess-shared.dir/src/set_fen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/set_fen.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/set_fen.cpp

CMakeFiles/libchess-shared.dir/src/set_fen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/set_fen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/set_fen.cpp > CMakeFiles/libchess-shared.dir/src/set_fen.cpp.i

CMakeFiles/libchess-shared.dir/src/set_fen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/set_fen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/set_fen.cpp -o CMakeFiles/libchess-shared.dir/src/set_fen.cpp.s

CMakeFiles/libchess-shared.dir/src/square_attacked.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/square_attacked.cpp.o: src/square_attacked.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/libchess-shared.dir/src/square_attacked.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/square_attacked.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/square_attacked.cpp

CMakeFiles/libchess-shared.dir/src/square_attacked.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/square_attacked.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/square_attacked.cpp > CMakeFiles/libchess-shared.dir/src/square_attacked.cpp.i

CMakeFiles/libchess-shared.dir/src/square_attacked.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/square_attacked.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/square_attacked.cpp -o CMakeFiles/libchess-shared.dir/src/square_attacked.cpp.s

CMakeFiles/libchess-shared.dir/src/squares_attacked.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/squares_attacked.cpp.o: src/squares_attacked.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/libchess-shared.dir/src/squares_attacked.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/squares_attacked.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/squares_attacked.cpp

CMakeFiles/libchess-shared.dir/src/squares_attacked.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/squares_attacked.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/squares_attacked.cpp > CMakeFiles/libchess-shared.dir/src/squares_attacked.cpp.i

CMakeFiles/libchess-shared.dir/src/squares_attacked.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/squares_attacked.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/squares_attacked.cpp -o CMakeFiles/libchess-shared.dir/src/squares_attacked.cpp.s

CMakeFiles/libchess-shared.dir/src/undomove.cpp.o: CMakeFiles/libchess-shared.dir/flags.make
CMakeFiles/libchess-shared.dir/src/undomove.cpp.o: src/undomove.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/libchess-shared.dir/src/undomove.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libchess-shared.dir/src/undomove.cpp.o -c /home/ufuk/Documents/yavuzWithC++/libchess/src/undomove.cpp

CMakeFiles/libchess-shared.dir/src/undomove.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libchess-shared.dir/src/undomove.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ufuk/Documents/yavuzWithC++/libchess/src/undomove.cpp > CMakeFiles/libchess-shared.dir/src/undomove.cpp.i

CMakeFiles/libchess-shared.dir/src/undomove.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libchess-shared.dir/src/undomove.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ufuk/Documents/yavuzWithC++/libchess/src/undomove.cpp -o CMakeFiles/libchess-shared.dir/src/undomove.cpp.s

# Object files for target libchess-shared
libchess__shared_OBJECTS = \
"CMakeFiles/libchess-shared.dir/src/attackers.cpp.o" \
"CMakeFiles/libchess-shared.dir/src/checkers.cpp.o" \
"CMakeFiles/libchess-shared.dir/src/check_evasions.cpp.o" \
"CMakeFiles/libchess-shared.dir/src/count_moves.cpp.o" \
"CMakeFiles/libchess-shared.dir/src/get_fen.cpp.o" \
"CMakeFiles/libchess-shared.dir/src/is_legal.cpp.o" \
"CMakeFiles/libchess-shared.dir/src/king_allowed.cpp.o" \
"CMakeFiles/libchess-shared.dir/src/legal_captures.cpp.o" \
"CMakeFiles/libchess-shared.dir/src/legal_moves.cpp.o" \
"CMakeFiles/libchess-shared.dir/src/legal_noncaptures.cpp.o" \
"CMakeFiles/libchess-shared.dir/src/makemove.cpp.o" \
"CMakeFiles/libchess-shared.dir/src/movegen.cpp.o" \
"CMakeFiles/libchess-shared.dir/src/perft.cpp.o" \
"CMakeFiles/libchess-shared.dir/src/pinned.cpp.o" \
"CMakeFiles/libchess-shared.dir/src/predict_hash.cpp.o" \
"CMakeFiles/libchess-shared.dir/src/set_fen.cpp.o" \
"CMakeFiles/libchess-shared.dir/src/square_attacked.cpp.o" \
"CMakeFiles/libchess-shared.dir/src/squares_attacked.cpp.o" \
"CMakeFiles/libchess-shared.dir/src/undomove.cpp.o"

# External object files for target libchess-shared
libchess__shared_EXTERNAL_OBJECTS =

shared/libchess.so: CMakeFiles/libchess-shared.dir/src/attackers.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/src/checkers.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/src/check_evasions.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/src/count_moves.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/src/get_fen.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/src/is_legal.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/src/king_allowed.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/src/legal_captures.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/src/legal_moves.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/src/legal_noncaptures.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/src/makemove.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/src/movegen.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/src/perft.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/src/pinned.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/src/predict_hash.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/src/set_fen.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/src/square_attacked.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/src/squares_attacked.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/src/undomove.cpp.o
shared/libchess.so: CMakeFiles/libchess-shared.dir/build.make
shared/libchess.so: CMakeFiles/libchess-shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Linking CXX shared library shared/libchess.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libchess-shared.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libchess-shared.dir/build: shared/libchess.so

.PHONY : CMakeFiles/libchess-shared.dir/build

CMakeFiles/libchess-shared.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libchess-shared.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libchess-shared.dir/clean

CMakeFiles/libchess-shared.dir/depend:
	cd /home/ufuk/Documents/yavuzWithC++/libchess && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ufuk/Documents/yavuzWithC++/libchess /home/ufuk/Documents/yavuzWithC++/libchess /home/ufuk/Documents/yavuzWithC++/libchess /home/ufuk/Documents/yavuzWithC++/libchess /home/ufuk/Documents/yavuzWithC++/libchess/CMakeFiles/libchess-shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libchess-shared.dir/depend

