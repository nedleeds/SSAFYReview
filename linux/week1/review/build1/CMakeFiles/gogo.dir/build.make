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
CMAKE_SOURCE_DIR = /home/lee/test/build1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lee/test/build1

# Include any dependencies generated for this target.
include CMakeFiles/gogo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gogo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gogo.dir/flags.make

CMakeFiles/gogo.dir/main.c.o: CMakeFiles/gogo.dir/flags.make
CMakeFiles/gogo.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lee/test/build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/gogo.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gogo.dir/main.c.o   -c /home/lee/test/build1/main.c

CMakeFiles/gogo.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gogo.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lee/test/build1/main.c > CMakeFiles/gogo.dir/main.c.i

CMakeFiles/gogo.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gogo.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lee/test/build1/main.c -o CMakeFiles/gogo.dir/main.c.s

CMakeFiles/gogo.dir/blue.c.o: CMakeFiles/gogo.dir/flags.make
CMakeFiles/gogo.dir/blue.c.o: blue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lee/test/build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/gogo.dir/blue.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gogo.dir/blue.c.o   -c /home/lee/test/build1/blue.c

CMakeFiles/gogo.dir/blue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gogo.dir/blue.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lee/test/build1/blue.c > CMakeFiles/gogo.dir/blue.c.i

CMakeFiles/gogo.dir/blue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gogo.dir/blue.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lee/test/build1/blue.c -o CMakeFiles/gogo.dir/blue.c.s

CMakeFiles/gogo.dir/pink.c.o: CMakeFiles/gogo.dir/flags.make
CMakeFiles/gogo.dir/pink.c.o: pink.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lee/test/build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/gogo.dir/pink.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gogo.dir/pink.c.o   -c /home/lee/test/build1/pink.c

CMakeFiles/gogo.dir/pink.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gogo.dir/pink.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lee/test/build1/pink.c > CMakeFiles/gogo.dir/pink.c.i

CMakeFiles/gogo.dir/pink.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gogo.dir/pink.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lee/test/build1/pink.c -o CMakeFiles/gogo.dir/pink.c.s

# Object files for target gogo
gogo_OBJECTS = \
"CMakeFiles/gogo.dir/main.c.o" \
"CMakeFiles/gogo.dir/blue.c.o" \
"CMakeFiles/gogo.dir/pink.c.o"

# External object files for target gogo
gogo_EXTERNAL_OBJECTS =

gogo: CMakeFiles/gogo.dir/main.c.o
gogo: CMakeFiles/gogo.dir/blue.c.o
gogo: CMakeFiles/gogo.dir/pink.c.o
gogo: CMakeFiles/gogo.dir/build.make
gogo: CMakeFiles/gogo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lee/test/build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable gogo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gogo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gogo.dir/build: gogo

.PHONY : CMakeFiles/gogo.dir/build

CMakeFiles/gogo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gogo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gogo.dir/clean

CMakeFiles/gogo.dir/depend:
	cd /home/lee/test/build1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lee/test/build1 /home/lee/test/build1 /home/lee/test/build1 /home/lee/test/build1 /home/lee/test/build1/CMakeFiles/gogo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gogo.dir/depend

