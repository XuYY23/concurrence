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
include bin/CMakeFiles/submit_future.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/submit_future.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/submit_future.dir/flags.make

bin/CMakeFiles/submit_future.dir/submit_future.cc.o: bin/CMakeFiles/submit_future.dir/flags.make
bin/CMakeFiles/submit_future.dir/submit_future.cc.o: ../examples/submit_future.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/king/cpp_concurrence/threadpool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/submit_future.dir/submit_future.cc.o"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/submit_future.dir/submit_future.cc.o -c /home/king/cpp_concurrence/threadpool/examples/submit_future.cc

bin/CMakeFiles/submit_future.dir/submit_future.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/submit_future.dir/submit_future.cc.i"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/king/cpp_concurrence/threadpool/examples/submit_future.cc > CMakeFiles/submit_future.dir/submit_future.cc.i

bin/CMakeFiles/submit_future.dir/submit_future.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/submit_future.dir/submit_future.cc.s"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/king/cpp_concurrence/threadpool/examples/submit_future.cc -o CMakeFiles/submit_future.dir/submit_future.cc.s

bin/CMakeFiles/submit_future.dir/__/src/cancel.cc.o: bin/CMakeFiles/submit_future.dir/flags.make
bin/CMakeFiles/submit_future.dir/__/src/cancel.cc.o: ../src/cancel.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/king/cpp_concurrence/threadpool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object bin/CMakeFiles/submit_future.dir/__/src/cancel.cc.o"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/submit_future.dir/__/src/cancel.cc.o -c /home/king/cpp_concurrence/threadpool/src/cancel.cc

bin/CMakeFiles/submit_future.dir/__/src/cancel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/submit_future.dir/__/src/cancel.cc.i"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/king/cpp_concurrence/threadpool/src/cancel.cc > CMakeFiles/submit_future.dir/__/src/cancel.cc.i

bin/CMakeFiles/submit_future.dir/__/src/cancel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/submit_future.dir/__/src/cancel.cc.s"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/king/cpp_concurrence/threadpool/src/cancel.cc -o CMakeFiles/submit_future.dir/__/src/cancel.cc.s

bin/CMakeFiles/submit_future.dir/__/src/io_util.cc.o: bin/CMakeFiles/submit_future.dir/flags.make
bin/CMakeFiles/submit_future.dir/__/src/io_util.cc.o: ../src/io_util.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/king/cpp_concurrence/threadpool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object bin/CMakeFiles/submit_future.dir/__/src/io_util.cc.o"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/submit_future.dir/__/src/io_util.cc.o -c /home/king/cpp_concurrence/threadpool/src/io_util.cc

bin/CMakeFiles/submit_future.dir/__/src/io_util.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/submit_future.dir/__/src/io_util.cc.i"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/king/cpp_concurrence/threadpool/src/io_util.cc > CMakeFiles/submit_future.dir/__/src/io_util.cc.i

bin/CMakeFiles/submit_future.dir/__/src/io_util.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/submit_future.dir/__/src/io_util.cc.s"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/king/cpp_concurrence/threadpool/src/io_util.cc -o CMakeFiles/submit_future.dir/__/src/io_util.cc.s

bin/CMakeFiles/submit_future.dir/__/src/thread_pool.cc.o: bin/CMakeFiles/submit_future.dir/flags.make
bin/CMakeFiles/submit_future.dir/__/src/thread_pool.cc.o: ../src/thread_pool.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/king/cpp_concurrence/threadpool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object bin/CMakeFiles/submit_future.dir/__/src/thread_pool.cc.o"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/submit_future.dir/__/src/thread_pool.cc.o -c /home/king/cpp_concurrence/threadpool/src/thread_pool.cc

bin/CMakeFiles/submit_future.dir/__/src/thread_pool.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/submit_future.dir/__/src/thread_pool.cc.i"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/king/cpp_concurrence/threadpool/src/thread_pool.cc > CMakeFiles/submit_future.dir/__/src/thread_pool.cc.i

bin/CMakeFiles/submit_future.dir/__/src/thread_pool.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/submit_future.dir/__/src/thread_pool.cc.s"
	cd /home/king/cpp_concurrence/threadpool/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/king/cpp_concurrence/threadpool/src/thread_pool.cc -o CMakeFiles/submit_future.dir/__/src/thread_pool.cc.s

# Object files for target submit_future
submit_future_OBJECTS = \
"CMakeFiles/submit_future.dir/submit_future.cc.o" \
"CMakeFiles/submit_future.dir/__/src/cancel.cc.o" \
"CMakeFiles/submit_future.dir/__/src/io_util.cc.o" \
"CMakeFiles/submit_future.dir/__/src/thread_pool.cc.o"

# External object files for target submit_future
submit_future_EXTERNAL_OBJECTS =

bin/submit_future: bin/CMakeFiles/submit_future.dir/submit_future.cc.o
bin/submit_future: bin/CMakeFiles/submit_future.dir/__/src/cancel.cc.o
bin/submit_future: bin/CMakeFiles/submit_future.dir/__/src/io_util.cc.o
bin/submit_future: bin/CMakeFiles/submit_future.dir/__/src/thread_pool.cc.o
bin/submit_future: bin/CMakeFiles/submit_future.dir/build.make
bin/submit_future: bin/CMakeFiles/submit_future.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/king/cpp_concurrence/threadpool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable submit_future"
	cd /home/king/cpp_concurrence/threadpool/build/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/submit_future.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/submit_future.dir/build: bin/submit_future

.PHONY : bin/CMakeFiles/submit_future.dir/build

bin/CMakeFiles/submit_future.dir/clean:
	cd /home/king/cpp_concurrence/threadpool/build/bin && $(CMAKE_COMMAND) -P CMakeFiles/submit_future.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/submit_future.dir/clean

bin/CMakeFiles/submit_future.dir/depend:
	cd /home/king/cpp_concurrence/threadpool/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/king/cpp_concurrence/threadpool /home/king/cpp_concurrence/threadpool/examples /home/king/cpp_concurrence/threadpool/build /home/king/cpp_concurrence/threadpool/build/bin /home/king/cpp_concurrence/threadpool/build/bin/CMakeFiles/submit_future.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/submit_future.dir/depend

