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


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/aodsaidou/Documents/s4/tents-a22b

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aodsaidou/Documents/s4/tents-a22b/build

# Include any dependencies generated for this target.
include CMakeFiles/game_solve.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game_solve.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game_solve.dir/flags.make

CMakeFiles/game_solve.dir/game_solve.c.o: CMakeFiles/game_solve.dir/flags.make
CMakeFiles/game_solve.dir/game_solve.c.o: ../game_solve.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aodsaidou/Documents/s4/tents-a22b/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/game_solve.dir/game_solve.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/game_solve.dir/game_solve.c.o   -c /home/aodsaidou/Documents/s4/tents-a22b/game_solve.c

CMakeFiles/game_solve.dir/game_solve.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game_solve.dir/game_solve.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aodsaidou/Documents/s4/tents-a22b/game_solve.c > CMakeFiles/game_solve.dir/game_solve.c.i

CMakeFiles/game_solve.dir/game_solve.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game_solve.dir/game_solve.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aodsaidou/Documents/s4/tents-a22b/game_solve.c -o CMakeFiles/game_solve.dir/game_solve.c.s

# Object files for target game_solve
game_solve_OBJECTS = \
"CMakeFiles/game_solve.dir/game_solve.c.o"

# External object files for target game_solve
game_solve_EXTERNAL_OBJECTS =

game_solve: CMakeFiles/game_solve.dir/game_solve.c.o
game_solve: CMakeFiles/game_solve.dir/build.make
game_solve: libgame.a
game_solve: CMakeFiles/game_solve.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aodsaidou/Documents/s4/tents-a22b/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable game_solve"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game_solve.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game_solve.dir/build: game_solve

.PHONY : CMakeFiles/game_solve.dir/build

CMakeFiles/game_solve.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game_solve.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game_solve.dir/clean

CMakeFiles/game_solve.dir/depend:
	cd /home/aodsaidou/Documents/s4/tents-a22b/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aodsaidou/Documents/s4/tents-a22b /home/aodsaidou/Documents/s4/tents-a22b /home/aodsaidou/Documents/s4/tents-a22b/build /home/aodsaidou/Documents/s4/tents-a22b/build /home/aodsaidou/Documents/s4/tents-a22b/build/CMakeFiles/game_solve.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game_solve.dir/depend
