# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/james/projects/Cara/init

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/james/projects/Cara

# Include any dependencies generated for this target.
include CMakeFiles/run.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/run.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run.dir/flags.make

CMakeFiles/run.dir/codegen:
.PHONY : CMakeFiles/run.dir/codegen

CMakeFiles/run.dir/cara/src/main.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/cara/src/main.cpp.o: cara/src/main.cpp
CMakeFiles/run.dir/cara/src/main.cpp.o: CMakeFiles/run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/james/projects/Cara/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/run.dir/cara/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run.dir/cara/src/main.cpp.o -MF CMakeFiles/run.dir/cara/src/main.cpp.o.d -o CMakeFiles/run.dir/cara/src/main.cpp.o -c /home/james/projects/Cara/cara/src/main.cpp

CMakeFiles/run.dir/cara/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run.dir/cara/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/james/projects/Cara/cara/src/main.cpp > CMakeFiles/run.dir/cara/src/main.cpp.i

CMakeFiles/run.dir/cara/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run.dir/cara/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/james/projects/Cara/cara/src/main.cpp -o CMakeFiles/run.dir/cara/src/main.cpp.s

CMakeFiles/run.dir/cara/src/cvm.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/cara/src/cvm.cpp.o: cara/src/cvm.cpp
CMakeFiles/run.dir/cara/src/cvm.cpp.o: CMakeFiles/run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/james/projects/Cara/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/run.dir/cara/src/cvm.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run.dir/cara/src/cvm.cpp.o -MF CMakeFiles/run.dir/cara/src/cvm.cpp.o.d -o CMakeFiles/run.dir/cara/src/cvm.cpp.o -c /home/james/projects/Cara/cara/src/cvm.cpp

CMakeFiles/run.dir/cara/src/cvm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run.dir/cara/src/cvm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/james/projects/Cara/cara/src/cvm.cpp > CMakeFiles/run.dir/cara/src/cvm.cpp.i

CMakeFiles/run.dir/cara/src/cvm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run.dir/cara/src/cvm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/james/projects/Cara/cara/src/cvm.cpp -o CMakeFiles/run.dir/cara/src/cvm.cpp.s

CMakeFiles/run.dir/cara/src/objects.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/cara/src/objects.cpp.o: cara/src/objects.cpp
CMakeFiles/run.dir/cara/src/objects.cpp.o: CMakeFiles/run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/james/projects/Cara/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/run.dir/cara/src/objects.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run.dir/cara/src/objects.cpp.o -MF CMakeFiles/run.dir/cara/src/objects.cpp.o.d -o CMakeFiles/run.dir/cara/src/objects.cpp.o -c /home/james/projects/Cara/cara/src/objects.cpp

CMakeFiles/run.dir/cara/src/objects.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run.dir/cara/src/objects.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/james/projects/Cara/cara/src/objects.cpp > CMakeFiles/run.dir/cara/src/objects.cpp.i

CMakeFiles/run.dir/cara/src/objects.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run.dir/cara/src/objects.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/james/projects/Cara/cara/src/objects.cpp -o CMakeFiles/run.dir/cara/src/objects.cpp.s

CMakeFiles/run.dir/cara/src/cara.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/cara/src/cara.cpp.o: cara/src/cara.cpp
CMakeFiles/run.dir/cara/src/cara.cpp.o: CMakeFiles/run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/james/projects/Cara/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/run.dir/cara/src/cara.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run.dir/cara/src/cara.cpp.o -MF CMakeFiles/run.dir/cara/src/cara.cpp.o.d -o CMakeFiles/run.dir/cara/src/cara.cpp.o -c /home/james/projects/Cara/cara/src/cara.cpp

CMakeFiles/run.dir/cara/src/cara.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run.dir/cara/src/cara.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/james/projects/Cara/cara/src/cara.cpp > CMakeFiles/run.dir/cara/src/cara.cpp.i

CMakeFiles/run.dir/cara/src/cara.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run.dir/cara/src/cara.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/james/projects/Cara/cara/src/cara.cpp -o CMakeFiles/run.dir/cara/src/cara.cpp.s

# Object files for target run
run_OBJECTS = \
"CMakeFiles/run.dir/cara/src/main.cpp.o" \
"CMakeFiles/run.dir/cara/src/cvm.cpp.o" \
"CMakeFiles/run.dir/cara/src/objects.cpp.o" \
"CMakeFiles/run.dir/cara/src/cara.cpp.o"

# External object files for target run
run_EXTERNAL_OBJECTS =

run: CMakeFiles/run.dir/cara/src/main.cpp.o
run: CMakeFiles/run.dir/cara/src/cvm.cpp.o
run: CMakeFiles/run.dir/cara/src/objects.cpp.o
run: CMakeFiles/run.dir/cara/src/cara.cpp.o
run: CMakeFiles/run.dir/build.make
run: CMakeFiles/run.dir/compiler_depend.ts
run: /usr/lib/libglfw.so.3.4
run: /usr/lib/libGLEW.so
run: /usr/lib/libGLX.so
run: /usr/lib/libOpenGL.so
run: CMakeFiles/run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/james/projects/Cara/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run.dir/build: run
.PHONY : CMakeFiles/run.dir/build

CMakeFiles/run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run.dir/clean

CMakeFiles/run.dir/depend:
	cd /home/james/projects/Cara && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/james/projects/Cara/init /home/james/projects/Cara/init /home/james/projects/Cara /home/james/projects/Cara /home/james/projects/Cara/CMakeFiles/run.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/run.dir/depend

