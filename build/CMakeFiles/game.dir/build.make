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
include CMakeFiles/game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/game_ext.c.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/game_ext.c.o: ../game_ext.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aodsaidou/Documents/s4/tents-a22b/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/game.dir/game_ext.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/game.dir/game_ext.c.o   -c /home/aodsaidou/Documents/s4/tents-a22b/game_ext.c

CMakeFiles/game.dir/game_ext.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game.dir/game_ext.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aodsaidou/Documents/s4/tents-a22b/game_ext.c > CMakeFiles/game.dir/game_ext.c.i

CMakeFiles/game.dir/game_ext.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game.dir/game_ext.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aodsaidou/Documents/s4/tents-a22b/game_ext.c -o CMakeFiles/game.dir/game_ext.c.s

CMakeFiles/game.dir/game.c.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/game.c.o: ../game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aodsaidou/Documents/s4/tents-a22b/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/game.dir/game.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/game.dir/game.c.o   -c /home/aodsaidou/Documents/s4/tents-a22b/game.c

CMakeFiles/game.dir/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game.dir/game.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aodsaidou/Documents/s4/tents-a22b/game.c > CMakeFiles/game.dir/game.c.i

CMakeFiles/game.dir/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game.dir/game.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aodsaidou/Documents/s4/tents-a22b/game.c -o CMakeFiles/game.dir/game.c.s

CMakeFiles/game.dir/game_private.c.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/game_private.c.o: ../game_private.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aodsaidou/Documents/s4/tents-a22b/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/game.dir/game_private.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/game.dir/game_private.c.o   -c /home/aodsaidou/Documents/s4/tents-a22b/game_private.c

CMakeFiles/game.dir/game_private.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game.dir/game_private.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aodsaidou/Documents/s4/tents-a22b/game_private.c > CMakeFiles/game.dir/game_private.c.i

CMakeFiles/game.dir/game_private.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game.dir/game_private.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aodsaidou/Documents/s4/tents-a22b/game_private.c -o CMakeFiles/game.dir/game_private.c.s

CMakeFiles/game.dir/game_aux.c.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/game_aux.c.o: ../game_aux.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aodsaidou/Documents/s4/tents-a22b/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/game.dir/game_aux.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/game.dir/game_aux.c.o   -c /home/aodsaidou/Documents/s4/tents-a22b/game_aux.c

CMakeFiles/game.dir/game_aux.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game.dir/game_aux.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aodsaidou/Documents/s4/tents-a22b/game_aux.c > CMakeFiles/game.dir/game_aux.c.i

CMakeFiles/game.dir/game_aux.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game.dir/game_aux.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aodsaidou/Documents/s4/tents-a22b/game_aux.c -o CMakeFiles/game.dir/game_aux.c.s

CMakeFiles/game.dir/queue.c.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/queue.c.o: ../queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aodsaidou/Documents/s4/tents-a22b/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/game.dir/queue.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/game.dir/queue.c.o   -c /home/aodsaidou/Documents/s4/tents-a22b/queue.c

CMakeFiles/game.dir/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game.dir/queue.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aodsaidou/Documents/s4/tents-a22b/queue.c > CMakeFiles/game.dir/queue.c.i

CMakeFiles/game.dir/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game.dir/queue.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aodsaidou/Documents/s4/tents-a22b/queue.c -o CMakeFiles/game.dir/queue.c.s

CMakeFiles/game.dir/game_tools.c.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/game_tools.c.o: ../game_tools.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aodsaidou/Documents/s4/tents-a22b/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/game.dir/game_tools.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/game.dir/game_tools.c.o   -c /home/aodsaidou/Documents/s4/tents-a22b/game_tools.c

CMakeFiles/game.dir/game_tools.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game.dir/game_tools.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aodsaidou/Documents/s4/tents-a22b/game_tools.c > CMakeFiles/game.dir/game_tools.c.i

CMakeFiles/game.dir/game_tools.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game.dir/game_tools.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aodsaidou/Documents/s4/tents-a22b/game_tools.c -o CMakeFiles/game.dir/game_tools.c.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/game_ext.c.o" \
"CMakeFiles/game.dir/game.c.o" \
"CMakeFiles/game.dir/game_private.c.o" \
"CMakeFiles/game.dir/game_aux.c.o" \
"CMakeFiles/game.dir/queue.c.o" \
"CMakeFiles/game.dir/game_tools.c.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

libgame.a: CMakeFiles/game.dir/game_ext.c.o
libgame.a: CMakeFiles/game.dir/game.c.o
libgame.a: CMakeFiles/game.dir/game_private.c.o
libgame.a: CMakeFiles/game.dir/game_aux.c.o
libgame.a: CMakeFiles/game.dir/queue.c.o
libgame.a: CMakeFiles/game.dir/game_tools.c.o
libgame.a: CMakeFiles/game.dir/build.make
libgame.a: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aodsaidou/Documents/s4/tents-a22b/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C static library libgame.a"
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: libgame.a

.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	cd /home/aodsaidou/Documents/s4/tents-a22b/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aodsaidou/Documents/s4/tents-a22b /home/aodsaidou/Documents/s4/tents-a22b /home/aodsaidou/Documents/s4/tents-a22b/build /home/aodsaidou/Documents/s4/tents-a22b/build /home/aodsaidou/Documents/s4/tents-a22b/build/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend

