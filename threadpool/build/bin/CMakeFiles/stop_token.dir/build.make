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
CMAKE_SOURCE_DIR = /home/king/cpp_concurrence/threadpool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/king/cpp_concurrence/threadpool/build

# Include any dependencies generated for this target.
include bin/CMakeFiles/stop_token.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/stop_token.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/stop_token.dir/flags.make

bin/CMakeFiles/stop_token.dir/stop_token.cc.o: bin/CMakeFiles/stop_token.dir/flags.make
bin/CMakeFiles/stop_token.dir/stop_token.cc.o: ../examples/stop_token.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/king/cpp_concurrence/threadpool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/stop_token.dir/stop_token.cc.o"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stop_token.dir/stop_token.cc.o -c /home/king/cpp_concurrence/threadpool/examples/stop_token.cc

bin/CMakeFiles/stop_token.dir/stop_token.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stop_token.dir/stop_token.cc.i"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/king/cpp_concurrence/threadpool/examples/stop_token.cc > CMakeFiles/stop_token.dir/stop_token.cc.i

bin/CMakeFiles/stop_token.dir/stop_token.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stop_token.dir/stop_token.cc.s"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/king/cpp_concurrence/threadpool/examples/stop_token.cc -o CMakeFiles/stop_token.dir/stop_token.cc.s

bin/CMakeFiles/stop_token.dir/__/src/cancel.cc.o: bin/CMakeFiles/stop_token.dir/flags.make
bin/CMakeFiles/stop_token.dir/__/src/cancel.cc.o: ../src/cancel.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/king/cpp_concurrence/threadpool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object bin/CMakeFiles/stop_token.dir/__/src/cancel.cc.o"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stop_token.dir/__/src/cancel.cc.o -c /home/king/cpp_concurrence/threadpool/src/cancel.cc

bin/CMakeFiles/stop_token.dir/__/src/cancel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stop_token.dir/__/src/cancel.cc.i"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/king/cpp_concurrence/threadpool/src/cancel.cc > CMakeFiles/stop_token.dir/__/src/cancel.cc.i

bin/CMakeFiles/stop_token.dir/__/src/cancel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stop_token.dir/__/src/cancel.cc.s"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/king/cpp_concurrence/threadpool/src/cancel.cc -o CMakeFiles/stop_token.dir/__/src/cancel.cc.s

bin/CMakeFiles/stop_token.dir/__/src/io_util.cc.o: bin/CMakeFiles/stop_token.dir/flags.make
bin/CMakeFiles/stop_token.dir/__/src/io_util.cc.o: ../src/io_util.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/king/cpp_concurrence/threadpool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object bin/CMakeFiles/stop_token.dir/__/src/io_util.cc.o"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stop_token.dir/__/src/io_util.cc.o -c /home/king/cpp_concurrence/threadpool/src/io_util.cc

bin/CMakeFiles/stop_token.dir/__/src/io_util.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stop_token.dir/__/src/io_util.cc.i"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/king/cpp_concurrence/threadpool/src/io_util.cc > CMakeFiles/stop_token.dir/__/src/io_util.cc.i

bin/CMakeFiles/stop_token.dir/__/src/io_util.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stop_token.dir/__/src/io_util.cc.s"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/king/cpp_concurrence/threadpool/src/io_util.cc -o CMakeFiles/stop_token.dir/__/src/io_util.cc.s

bin/CMakeFiles/stop_token.dir/__/src/thread_pool.cc.o: bin/CMakeFiles/stop_token.dir/flags.make
bin/CMakeFiles/stop_token.dir/__/src/thread_pool.cc.o: ../src/thread_pool.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/king/cpp_concurrence/threadpool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object bin/CMakeFiles/stop_token.dir/__/src/thread_pool.cc.o"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stop_token.dir/__/src/thread_pool.cc.o -c /home/king/cpp_concurrence/threadpool/src/thread_pool.cc

bin/CMakeFiles/stop_token.dir/__/src/thread_pool.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stop_token.dir/__/src/thread_pool.cc.i"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/king/cpp_concurrence/threadpool/src/thread_pool.cc > CMakeFiles/stop_token.dir/__/src/thread_pool.cc.i

bin/CMakeFiles/stop_token.dir/__/src/thread_pool.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stop_token.dir/__/src/thread_pool.cc.s"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/king/cpp_concurrence/threadpool/src/thread_pool.cc -o CMakeFiles/stop_token.dir/__/src/thread_pool.cc.s

# Object files for target stop_token
stop_token_OBJECTS = \
"CMakeFiles/stop_token.dir/stop_token.cc.o" \
"CMakeFiles/stop_token.dir/__/src/cancel.cc.o" \
"CMakeFiles/stop_token.dir/__/src/io_util.cc.o" \
"CMakeFiles/stop_token.dir/__/src/thread_pool.cc.o"

# External object files for target stop_token
stop_token_EXTERNAL_OBJECTS =

bin/stop_token: bin/CMakeFiles/stop_token.dir/stop_token.cc.o
bin/stop_token: bin/CMakeFiles/stop_token.dir/__/src/cancel.cc.o
bin/stop_token: bin/CMakeFiles/stop_token.dir/__/src/io_util.cc.o
bin/stop_token: bin/CMakeFiles/stop_token.dir/__/src/thread_pool.cc.o
bin/stop_token: bin/CMakeFiles/stop_token.dir/build.make
bin/stop_token: bin/CMakeFiles/stop_token.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/king/cpp_concurrence/threadpool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable stop_token"
	cd /home/king/cpp_concurrence/threadpool/build/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stop_token.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/stop_token.dir/build: bin/stop_token

.PHONY : bin/CMakeFiles/stop_token.dir/build

bin/CMakeFiles/stop_token.dir/clean:
	cd /home/king/cpp_concurrence/threadpool/build/bin && $(CMAKE_COMMAND) -P CMakeFiles/stop_token.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/stop_token.dir/clean

bin/CMakeFiles/stop_token.dir/depend:
	cd /home/king/cpp_concurrence/threadpool/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/king/cpp_concurrence/threadpool /home/king/cpp_concurrence/threadpool/examples /home/king/cpp_concurrence/threadpool/build /home/king/cpp_concurrence/threadpool/build/bin /home/king/cpp_concurrence/threadpool/build/bin/CMakeFiles/stop_token.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/stop_token.dir/depend

