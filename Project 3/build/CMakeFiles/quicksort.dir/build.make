# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/student/Documents/Project 3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/student/Documents/Project 3/build"

# Include any dependencies generated for this target.
include CMakeFiles/quicksort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/quicksort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/quicksort.dir/flags.make

CMakeFiles/quicksort.dir/Main.cpp.o: CMakeFiles/quicksort.dir/flags.make
CMakeFiles/quicksort.dir/Main.cpp.o: ../Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/student/Documents/Project 3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/quicksort.dir/Main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/quicksort.dir/Main.cpp.o -c "/home/student/Documents/Project 3/Main.cpp"

CMakeFiles/quicksort.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/quicksort.dir/Main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/student/Documents/Project 3/Main.cpp" > CMakeFiles/quicksort.dir/Main.cpp.i

CMakeFiles/quicksort.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/quicksort.dir/Main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/student/Documents/Project 3/Main.cpp" -o CMakeFiles/quicksort.dir/Main.cpp.s

CMakeFiles/quicksort.dir/Main.cpp.o.requires:

.PHONY : CMakeFiles/quicksort.dir/Main.cpp.o.requires

CMakeFiles/quicksort.dir/Main.cpp.o.provides: CMakeFiles/quicksort.dir/Main.cpp.o.requires
	$(MAKE) -f CMakeFiles/quicksort.dir/build.make CMakeFiles/quicksort.dir/Main.cpp.o.provides.build
.PHONY : CMakeFiles/quicksort.dir/Main.cpp.o.provides

CMakeFiles/quicksort.dir/Main.cpp.o.provides.build: CMakeFiles/quicksort.dir/Main.cpp.o


# Object files for target quicksort
quicksort_OBJECTS = \
"CMakeFiles/quicksort.dir/Main.cpp.o"

# External object files for target quicksort
quicksort_EXTERNAL_OBJECTS =

quicksort: CMakeFiles/quicksort.dir/Main.cpp.o
quicksort: CMakeFiles/quicksort.dir/build.make
quicksort: CMakeFiles/quicksort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/student/Documents/Project 3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable quicksort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/quicksort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/quicksort.dir/build: quicksort

.PHONY : CMakeFiles/quicksort.dir/build

CMakeFiles/quicksort.dir/requires: CMakeFiles/quicksort.dir/Main.cpp.o.requires

.PHONY : CMakeFiles/quicksort.dir/requires

CMakeFiles/quicksort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/quicksort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/quicksort.dir/clean

CMakeFiles/quicksort.dir/depend:
	cd "/home/student/Documents/Project 3/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/student/Documents/Project 3" "/home/student/Documents/Project 3" "/home/student/Documents/Project 3/build" "/home/student/Documents/Project 3/build" "/home/student/Documents/Project 3/build/CMakeFiles/quicksort.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/quicksort.dir/depend

