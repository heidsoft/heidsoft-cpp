# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_05

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_05

# Include any dependencies generated for this target.
include CMakeFiles/heidsoft.exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/heidsoft.exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/heidsoft.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/heidsoft.exe.dir/flags.make

CMakeFiles/heidsoft.exe.dir/main.c.o: CMakeFiles/heidsoft.exe.dir/flags.make
CMakeFiles/heidsoft.exe.dir/main.c.o: main.c
CMakeFiles/heidsoft.exe.dir/main.c.o: CMakeFiles/heidsoft.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_05/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/heidsoft.exe.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/heidsoft.exe.dir/main.c.o -MF CMakeFiles/heidsoft.exe.dir/main.c.o.d -o CMakeFiles/heidsoft.exe.dir/main.c.o -c /Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_05/main.c

CMakeFiles/heidsoft.exe.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/heidsoft.exe.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_05/main.c > CMakeFiles/heidsoft.exe.dir/main.c.i

CMakeFiles/heidsoft.exe.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/heidsoft.exe.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_05/main.c -o CMakeFiles/heidsoft.exe.dir/main.c.s

# Object files for target heidsoft.exe
heidsoft_exe_OBJECTS = \
"CMakeFiles/heidsoft.exe.dir/main.c.o"

# External object files for target heidsoft.exe
heidsoft_exe_EXTERNAL_OBJECTS =

heidsoft.exe: CMakeFiles/heidsoft.exe.dir/main.c.o
heidsoft.exe: CMakeFiles/heidsoft.exe.dir/build.make
heidsoft.exe: CMakeFiles/heidsoft.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_05/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable heidsoft.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/heidsoft.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/heidsoft.exe.dir/build: heidsoft.exe
.PHONY : CMakeFiles/heidsoft.exe.dir/build

CMakeFiles/heidsoft.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/heidsoft.exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/heidsoft.exe.dir/clean

CMakeFiles/heidsoft.exe.dir/depend:
	cd /Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_05 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_05 /Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_05 /Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_05 /Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_05 /Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_05/CMakeFiles/heidsoft.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/heidsoft.exe.dir/depend
