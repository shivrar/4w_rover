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
CMAKE_COMMAND = /home/shivan/clion-2019.2.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/shivan/clion-2019.2.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shivan/arduino_pio/encoders

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shivan/arduino_pio/encoders/cmake-build-uno

# Include any dependencies generated for this target.
include CMakeFiles/Z_DUMMY_TARGET.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Z_DUMMY_TARGET.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Z_DUMMY_TARGET.dir/flags.make

CMakeFiles/Z_DUMMY_TARGET.dir/src/Encoders.cpp.obj: CMakeFiles/Z_DUMMY_TARGET.dir/flags.make
CMakeFiles/Z_DUMMY_TARGET.dir/src/Encoders.cpp.obj: ../src/Encoders.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shivan/arduino_pio/encoders/cmake-build-uno/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Z_DUMMY_TARGET.dir/src/Encoders.cpp.obj"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Z_DUMMY_TARGET.dir/src/Encoders.cpp.obj -c /home/shivan/arduino_pio/encoders/src/Encoders.cpp

CMakeFiles/Z_DUMMY_TARGET.dir/src/Encoders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Z_DUMMY_TARGET.dir/src/Encoders.cpp.i"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shivan/arduino_pio/encoders/src/Encoders.cpp > CMakeFiles/Z_DUMMY_TARGET.dir/src/Encoders.cpp.i

CMakeFiles/Z_DUMMY_TARGET.dir/src/Encoders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Z_DUMMY_TARGET.dir/src/Encoders.cpp.s"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shivan/arduino_pio/encoders/src/Encoders.cpp -o CMakeFiles/Z_DUMMY_TARGET.dir/src/Encoders.cpp.s

CMakeFiles/Z_DUMMY_TARGET.dir/src/main.cpp.obj: CMakeFiles/Z_DUMMY_TARGET.dir/flags.make
CMakeFiles/Z_DUMMY_TARGET.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shivan/arduino_pio/encoders/cmake-build-uno/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Z_DUMMY_TARGET.dir/src/main.cpp.obj"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Z_DUMMY_TARGET.dir/src/main.cpp.obj -c /home/shivan/arduino_pio/encoders/src/main.cpp

CMakeFiles/Z_DUMMY_TARGET.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Z_DUMMY_TARGET.dir/src/main.cpp.i"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shivan/arduino_pio/encoders/src/main.cpp > CMakeFiles/Z_DUMMY_TARGET.dir/src/main.cpp.i

CMakeFiles/Z_DUMMY_TARGET.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Z_DUMMY_TARGET.dir/src/main.cpp.s"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shivan/arduino_pio/encoders/src/main.cpp -o CMakeFiles/Z_DUMMY_TARGET.dir/src/main.cpp.s

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/croutine.c.obj: CMakeFiles/Z_DUMMY_TARGET.dir/flags.make
CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/croutine.c.obj: ../.pio/libdeps/uno/FreeRTOS/src/croutine.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shivan/arduino_pio/encoders/cmake-build-uno/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/croutine.c.obj"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/croutine.c.obj   -c /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/croutine.c

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/croutine.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/croutine.c.i"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/croutine.c > CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/croutine.c.i

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/croutine.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/croutine.c.s"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/croutine.c -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/croutine.c.s

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/event_groups.c.obj: CMakeFiles/Z_DUMMY_TARGET.dir/flags.make
CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/event_groups.c.obj: ../.pio/libdeps/uno/FreeRTOS/src/event_groups.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shivan/arduino_pio/encoders/cmake-build-uno/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/event_groups.c.obj"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/event_groups.c.obj   -c /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/event_groups.c

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/event_groups.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/event_groups.c.i"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/event_groups.c > CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/event_groups.c.i

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/event_groups.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/event_groups.c.s"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/event_groups.c -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/event_groups.c.s

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/heap_3.c.obj: CMakeFiles/Z_DUMMY_TARGET.dir/flags.make
CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/heap_3.c.obj: ../.pio/libdeps/uno/FreeRTOS/src/heap_3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shivan/arduino_pio/encoders/cmake-build-uno/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/heap_3.c.obj"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/heap_3.c.obj   -c /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/heap_3.c

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/heap_3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/heap_3.c.i"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/heap_3.c > CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/heap_3.c.i

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/heap_3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/heap_3.c.s"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/heap_3.c -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/heap_3.c.s

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/list.c.obj: CMakeFiles/Z_DUMMY_TARGET.dir/flags.make
CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/list.c.obj: ../.pio/libdeps/uno/FreeRTOS/src/list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shivan/arduino_pio/encoders/cmake-build-uno/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/list.c.obj"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/list.c.obj   -c /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/list.c

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/list.c.i"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/list.c > CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/list.c.i

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/list.c.s"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/list.c -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/list.c.s

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/port.c.obj: CMakeFiles/Z_DUMMY_TARGET.dir/flags.make
CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/port.c.obj: ../.pio/libdeps/uno/FreeRTOS/src/port.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shivan/arduino_pio/encoders/cmake-build-uno/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/port.c.obj"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/port.c.obj   -c /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/port.c

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/port.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/port.c.i"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/port.c > CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/port.c.i

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/port.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/port.c.s"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/port.c -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/port.c.s

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/queue.c.obj: CMakeFiles/Z_DUMMY_TARGET.dir/flags.make
CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/queue.c.obj: ../.pio/libdeps/uno/FreeRTOS/src/queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shivan/arduino_pio/encoders/cmake-build-uno/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/queue.c.obj"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/queue.c.obj   -c /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/queue.c

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/queue.c.i"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/queue.c > CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/queue.c.i

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/queue.c.s"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/queue.c -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/queue.c.s

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/stream_buffer.c.obj: CMakeFiles/Z_DUMMY_TARGET.dir/flags.make
CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/stream_buffer.c.obj: ../.pio/libdeps/uno/FreeRTOS/src/stream_buffer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shivan/arduino_pio/encoders/cmake-build-uno/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/stream_buffer.c.obj"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/stream_buffer.c.obj   -c /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/stream_buffer.c

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/stream_buffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/stream_buffer.c.i"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/stream_buffer.c > CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/stream_buffer.c.i

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/stream_buffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/stream_buffer.c.s"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/stream_buffer.c -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/stream_buffer.c.s

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/tasks.c.obj: CMakeFiles/Z_DUMMY_TARGET.dir/flags.make
CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/tasks.c.obj: ../.pio/libdeps/uno/FreeRTOS/src/tasks.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shivan/arduino_pio/encoders/cmake-build-uno/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/tasks.c.obj"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/tasks.c.obj   -c /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/tasks.c

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/tasks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/tasks.c.i"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/tasks.c > CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/tasks.c.i

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/tasks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/tasks.c.s"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/tasks.c -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/tasks.c.s

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/timers.c.obj: CMakeFiles/Z_DUMMY_TARGET.dir/flags.make
CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/timers.c.obj: ../.pio/libdeps/uno/FreeRTOS/src/timers.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shivan/arduino_pio/encoders/cmake-build-uno/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/timers.c.obj"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/timers.c.obj   -c /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/timers.c

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/timers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/timers.c.i"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/timers.c > CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/timers.c.i

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/timers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/timers.c.s"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/timers.c -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/timers.c.s

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/variantHooks.cpp.obj: CMakeFiles/Z_DUMMY_TARGET.dir/flags.make
CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/variantHooks.cpp.obj: ../.pio/libdeps/uno/FreeRTOS/src/variantHooks.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shivan/arduino_pio/encoders/cmake-build-uno/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/variantHooks.cpp.obj"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/variantHooks.cpp.obj -c /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/variantHooks.cpp

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/variantHooks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/variantHooks.cpp.i"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/variantHooks.cpp > CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/variantHooks.cpp.i

CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/variantHooks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/variantHooks.cpp.s"
	/home/shivan/.platformio/packages/toolchain-atmelavr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shivan/arduino_pio/encoders/.pio/libdeps/uno/FreeRTOS/src/variantHooks.cpp -o CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/variantHooks.cpp.s

# Object files for target Z_DUMMY_TARGET
Z_DUMMY_TARGET_OBJECTS = \
"CMakeFiles/Z_DUMMY_TARGET.dir/src/Encoders.cpp.obj" \
"CMakeFiles/Z_DUMMY_TARGET.dir/src/main.cpp.obj" \
"CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/croutine.c.obj" \
"CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/event_groups.c.obj" \
"CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/heap_3.c.obj" \
"CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/list.c.obj" \
"CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/port.c.obj" \
"CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/queue.c.obj" \
"CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/stream_buffer.c.obj" \
"CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/tasks.c.obj" \
"CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/timers.c.obj" \
"CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/variantHooks.cpp.obj"

# External object files for target Z_DUMMY_TARGET
Z_DUMMY_TARGET_EXTERNAL_OBJECTS =

Z_DUMMY_TARGET: CMakeFiles/Z_DUMMY_TARGET.dir/src/Encoders.cpp.obj
Z_DUMMY_TARGET: CMakeFiles/Z_DUMMY_TARGET.dir/src/main.cpp.obj
Z_DUMMY_TARGET: CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/croutine.c.obj
Z_DUMMY_TARGET: CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/event_groups.c.obj
Z_DUMMY_TARGET: CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/heap_3.c.obj
Z_DUMMY_TARGET: CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/list.c.obj
Z_DUMMY_TARGET: CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/port.c.obj
Z_DUMMY_TARGET: CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/queue.c.obj
Z_DUMMY_TARGET: CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/stream_buffer.c.obj
Z_DUMMY_TARGET: CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/tasks.c.obj
Z_DUMMY_TARGET: CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/timers.c.obj
Z_DUMMY_TARGET: CMakeFiles/Z_DUMMY_TARGET.dir/.pio/libdeps/uno/FreeRTOS/src/variantHooks.cpp.obj
Z_DUMMY_TARGET: CMakeFiles/Z_DUMMY_TARGET.dir/build.make
Z_DUMMY_TARGET: CMakeFiles/Z_DUMMY_TARGET.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shivan/arduino_pio/encoders/cmake-build-uno/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable Z_DUMMY_TARGET"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Z_DUMMY_TARGET.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Z_DUMMY_TARGET.dir/build: Z_DUMMY_TARGET

.PHONY : CMakeFiles/Z_DUMMY_TARGET.dir/build

CMakeFiles/Z_DUMMY_TARGET.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Z_DUMMY_TARGET.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Z_DUMMY_TARGET.dir/clean

CMakeFiles/Z_DUMMY_TARGET.dir/depend:
	cd /home/shivan/arduino_pio/encoders/cmake-build-uno && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shivan/arduino_pio/encoders /home/shivan/arduino_pio/encoders /home/shivan/arduino_pio/encoders/cmake-build-uno /home/shivan/arduino_pio/encoders/cmake-build-uno /home/shivan/arduino_pio/encoders/cmake-build-uno/CMakeFiles/Z_DUMMY_TARGET.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Z_DUMMY_TARGET.dir/depend
