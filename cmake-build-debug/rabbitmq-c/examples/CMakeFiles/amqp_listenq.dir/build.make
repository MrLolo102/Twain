# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/126/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/126/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug

# Include any dependencies generated for this target.
include rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/depend.make

# Include the progress variables for this target.
include rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/progress.make

# Include the compile flags for this target's objects.
include rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/flags.make

rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/amqp_listenq.c.o: rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/flags.make
rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/amqp_listenq.c.o: ../rabbitmq-c/examples/amqp_listenq.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/amqp_listenq.c.o"
	cd /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug/rabbitmq-c/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/amqp_listenq.dir/amqp_listenq.c.o   -c /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/rabbitmq-c/examples/amqp_listenq.c

rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/amqp_listenq.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/amqp_listenq.dir/amqp_listenq.c.i"
	cd /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug/rabbitmq-c/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/rabbitmq-c/examples/amqp_listenq.c > CMakeFiles/amqp_listenq.dir/amqp_listenq.c.i

rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/amqp_listenq.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/amqp_listenq.dir/amqp_listenq.c.s"
	cd /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug/rabbitmq-c/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/rabbitmq-c/examples/amqp_listenq.c -o CMakeFiles/amqp_listenq.dir/amqp_listenq.c.s

rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/utils.c.o: rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/flags.make
rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/utils.c.o: ../rabbitmq-c/examples/utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/utils.c.o"
	cd /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug/rabbitmq-c/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/amqp_listenq.dir/utils.c.o   -c /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/rabbitmq-c/examples/utils.c

rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/amqp_listenq.dir/utils.c.i"
	cd /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug/rabbitmq-c/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/rabbitmq-c/examples/utils.c > CMakeFiles/amqp_listenq.dir/utils.c.i

rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/amqp_listenq.dir/utils.c.s"
	cd /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug/rabbitmq-c/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/rabbitmq-c/examples/utils.c -o CMakeFiles/amqp_listenq.dir/utils.c.s

rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/unix/platform_utils.c.o: rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/flags.make
rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/unix/platform_utils.c.o: ../rabbitmq-c/examples/unix/platform_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/unix/platform_utils.c.o"
	cd /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug/rabbitmq-c/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/amqp_listenq.dir/unix/platform_utils.c.o   -c /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/rabbitmq-c/examples/unix/platform_utils.c

rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/unix/platform_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/amqp_listenq.dir/unix/platform_utils.c.i"
	cd /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug/rabbitmq-c/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/rabbitmq-c/examples/unix/platform_utils.c > CMakeFiles/amqp_listenq.dir/unix/platform_utils.c.i

rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/unix/platform_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/amqp_listenq.dir/unix/platform_utils.c.s"
	cd /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug/rabbitmq-c/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/rabbitmq-c/examples/unix/platform_utils.c -o CMakeFiles/amqp_listenq.dir/unix/platform_utils.c.s

# Object files for target amqp_listenq
amqp_listenq_OBJECTS = \
"CMakeFiles/amqp_listenq.dir/amqp_listenq.c.o" \
"CMakeFiles/amqp_listenq.dir/utils.c.o" \
"CMakeFiles/amqp_listenq.dir/unix/platform_utils.c.o"

# External object files for target amqp_listenq
amqp_listenq_EXTERNAL_OBJECTS =

rabbitmq-c/examples/amqp_listenq: rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/amqp_listenq.c.o
rabbitmq-c/examples/amqp_listenq: rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/utils.c.o
rabbitmq-c/examples/amqp_listenq: rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/unix/platform_utils.c.o
rabbitmq-c/examples/amqp_listenq: rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/build.make
rabbitmq-c/examples/amqp_listenq: rabbitmq-c/librabbitmq/librabbitmq.so.4.4.1
rabbitmq-c/examples/amqp_listenq: /usr/lib/x86_64-linux-gnu/libssl.so
rabbitmq-c/examples/amqp_listenq: /usr/lib/x86_64-linux-gnu/libcrypto.so
rabbitmq-c/examples/amqp_listenq: rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable amqp_listenq"
	cd /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug/rabbitmq-c/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/amqp_listenq.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/build: rabbitmq-c/examples/amqp_listenq

.PHONY : rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/build

rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/clean:
	cd /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug/rabbitmq-c/examples && $(CMAKE_COMMAND) -P CMakeFiles/amqp_listenq.dir/cmake_clean.cmake
.PHONY : rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/clean

rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/depend:
	cd /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/rabbitmq-c/examples /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug/rabbitmq-c/examples /home/adminhp/Desktop/Vmodev/twain-rabbitmq-client/cmake-build-debug/rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : rabbitmq-c/examples/CMakeFiles/amqp_listenq.dir/depend

