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
CMAKE_SOURCE_DIR = /home/qigao/qigao/linux_learn/manager/LowerComp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qigao/qigao/linux_learn/manager/LowerComp/build

# Include any dependencies generated for this target.
include lib/nmealib/CMakeFiles/nmea.dir/depend.make

# Include the progress variables for this target.
include lib/nmealib/CMakeFiles/nmea.dir/progress.make

# Include the compile flags for this target's objects.
include lib/nmealib/CMakeFiles/nmea.dir/flags.make

lib/nmealib/CMakeFiles/nmea.dir/src/context.c.o: lib/nmealib/CMakeFiles/nmea.dir/flags.make
lib/nmealib/CMakeFiles/nmea.dir/src/context.c.o: ../lib/nmealib/src/context.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qigao/qigao/linux_learn/manager/LowerComp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/nmealib/CMakeFiles/nmea.dir/src/context.c.o"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nmea.dir/src/context.c.o   -c /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/context.c

lib/nmealib/CMakeFiles/nmea.dir/src/context.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nmea.dir/src/context.c.i"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/context.c > CMakeFiles/nmea.dir/src/context.c.i

lib/nmealib/CMakeFiles/nmea.dir/src/context.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nmea.dir/src/context.c.s"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/context.c -o CMakeFiles/nmea.dir/src/context.c.s

lib/nmealib/CMakeFiles/nmea.dir/src/generate.c.o: lib/nmealib/CMakeFiles/nmea.dir/flags.make
lib/nmealib/CMakeFiles/nmea.dir/src/generate.c.o: ../lib/nmealib/src/generate.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qigao/qigao/linux_learn/manager/LowerComp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/nmealib/CMakeFiles/nmea.dir/src/generate.c.o"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nmea.dir/src/generate.c.o   -c /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/generate.c

lib/nmealib/CMakeFiles/nmea.dir/src/generate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nmea.dir/src/generate.c.i"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/generate.c > CMakeFiles/nmea.dir/src/generate.c.i

lib/nmealib/CMakeFiles/nmea.dir/src/generate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nmea.dir/src/generate.c.s"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/generate.c -o CMakeFiles/nmea.dir/src/generate.c.s

lib/nmealib/CMakeFiles/nmea.dir/src/generator.c.o: lib/nmealib/CMakeFiles/nmea.dir/flags.make
lib/nmealib/CMakeFiles/nmea.dir/src/generator.c.o: ../lib/nmealib/src/generator.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qigao/qigao/linux_learn/manager/LowerComp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object lib/nmealib/CMakeFiles/nmea.dir/src/generator.c.o"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nmea.dir/src/generator.c.o   -c /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/generator.c

lib/nmealib/CMakeFiles/nmea.dir/src/generator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nmea.dir/src/generator.c.i"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/generator.c > CMakeFiles/nmea.dir/src/generator.c.i

lib/nmealib/CMakeFiles/nmea.dir/src/generator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nmea.dir/src/generator.c.s"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/generator.c -o CMakeFiles/nmea.dir/src/generator.c.s

lib/nmealib/CMakeFiles/nmea.dir/src/gmath.c.o: lib/nmealib/CMakeFiles/nmea.dir/flags.make
lib/nmealib/CMakeFiles/nmea.dir/src/gmath.c.o: ../lib/nmealib/src/gmath.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qigao/qigao/linux_learn/manager/LowerComp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object lib/nmealib/CMakeFiles/nmea.dir/src/gmath.c.o"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nmea.dir/src/gmath.c.o   -c /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/gmath.c

lib/nmealib/CMakeFiles/nmea.dir/src/gmath.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nmea.dir/src/gmath.c.i"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/gmath.c > CMakeFiles/nmea.dir/src/gmath.c.i

lib/nmealib/CMakeFiles/nmea.dir/src/gmath.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nmea.dir/src/gmath.c.s"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/gmath.c -o CMakeFiles/nmea.dir/src/gmath.c.s

lib/nmealib/CMakeFiles/nmea.dir/src/info.c.o: lib/nmealib/CMakeFiles/nmea.dir/flags.make
lib/nmealib/CMakeFiles/nmea.dir/src/info.c.o: ../lib/nmealib/src/info.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qigao/qigao/linux_learn/manager/LowerComp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object lib/nmealib/CMakeFiles/nmea.dir/src/info.c.o"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nmea.dir/src/info.c.o   -c /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/info.c

lib/nmealib/CMakeFiles/nmea.dir/src/info.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nmea.dir/src/info.c.i"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/info.c > CMakeFiles/nmea.dir/src/info.c.i

lib/nmealib/CMakeFiles/nmea.dir/src/info.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nmea.dir/src/info.c.s"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/info.c -o CMakeFiles/nmea.dir/src/info.c.s

lib/nmealib/CMakeFiles/nmea.dir/src/parse.c.o: lib/nmealib/CMakeFiles/nmea.dir/flags.make
lib/nmealib/CMakeFiles/nmea.dir/src/parse.c.o: ../lib/nmealib/src/parse.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qigao/qigao/linux_learn/manager/LowerComp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object lib/nmealib/CMakeFiles/nmea.dir/src/parse.c.o"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nmea.dir/src/parse.c.o   -c /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/parse.c

lib/nmealib/CMakeFiles/nmea.dir/src/parse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nmea.dir/src/parse.c.i"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/parse.c > CMakeFiles/nmea.dir/src/parse.c.i

lib/nmealib/CMakeFiles/nmea.dir/src/parse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nmea.dir/src/parse.c.s"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/parse.c -o CMakeFiles/nmea.dir/src/parse.c.s

lib/nmealib/CMakeFiles/nmea.dir/src/parser.c.o: lib/nmealib/CMakeFiles/nmea.dir/flags.make
lib/nmealib/CMakeFiles/nmea.dir/src/parser.c.o: ../lib/nmealib/src/parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qigao/qigao/linux_learn/manager/LowerComp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object lib/nmealib/CMakeFiles/nmea.dir/src/parser.c.o"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nmea.dir/src/parser.c.o   -c /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/parser.c

lib/nmealib/CMakeFiles/nmea.dir/src/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nmea.dir/src/parser.c.i"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/parser.c > CMakeFiles/nmea.dir/src/parser.c.i

lib/nmealib/CMakeFiles/nmea.dir/src/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nmea.dir/src/parser.c.s"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/parser.c -o CMakeFiles/nmea.dir/src/parser.c.s

lib/nmealib/CMakeFiles/nmea.dir/src/sentence.c.o: lib/nmealib/CMakeFiles/nmea.dir/flags.make
lib/nmealib/CMakeFiles/nmea.dir/src/sentence.c.o: ../lib/nmealib/src/sentence.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qigao/qigao/linux_learn/manager/LowerComp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object lib/nmealib/CMakeFiles/nmea.dir/src/sentence.c.o"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nmea.dir/src/sentence.c.o   -c /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/sentence.c

lib/nmealib/CMakeFiles/nmea.dir/src/sentence.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nmea.dir/src/sentence.c.i"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/sentence.c > CMakeFiles/nmea.dir/src/sentence.c.i

lib/nmealib/CMakeFiles/nmea.dir/src/sentence.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nmea.dir/src/sentence.c.s"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/sentence.c -o CMakeFiles/nmea.dir/src/sentence.c.s

lib/nmealib/CMakeFiles/nmea.dir/src/time.c.o: lib/nmealib/CMakeFiles/nmea.dir/flags.make
lib/nmealib/CMakeFiles/nmea.dir/src/time.c.o: ../lib/nmealib/src/time.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qigao/qigao/linux_learn/manager/LowerComp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object lib/nmealib/CMakeFiles/nmea.dir/src/time.c.o"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nmea.dir/src/time.c.o   -c /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/time.c

lib/nmealib/CMakeFiles/nmea.dir/src/time.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nmea.dir/src/time.c.i"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/time.c > CMakeFiles/nmea.dir/src/time.c.i

lib/nmealib/CMakeFiles/nmea.dir/src/time.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nmea.dir/src/time.c.s"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/time.c -o CMakeFiles/nmea.dir/src/time.c.s

lib/nmealib/CMakeFiles/nmea.dir/src/tok.c.o: lib/nmealib/CMakeFiles/nmea.dir/flags.make
lib/nmealib/CMakeFiles/nmea.dir/src/tok.c.o: ../lib/nmealib/src/tok.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qigao/qigao/linux_learn/manager/LowerComp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object lib/nmealib/CMakeFiles/nmea.dir/src/tok.c.o"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nmea.dir/src/tok.c.o   -c /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/tok.c

lib/nmealib/CMakeFiles/nmea.dir/src/tok.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nmea.dir/src/tok.c.i"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/tok.c > CMakeFiles/nmea.dir/src/tok.c.i

lib/nmealib/CMakeFiles/nmea.dir/src/tok.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nmea.dir/src/tok.c.s"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && arm-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib/src/tok.c -o CMakeFiles/nmea.dir/src/tok.c.s

# Object files for target nmea
nmea_OBJECTS = \
"CMakeFiles/nmea.dir/src/context.c.o" \
"CMakeFiles/nmea.dir/src/generate.c.o" \
"CMakeFiles/nmea.dir/src/generator.c.o" \
"CMakeFiles/nmea.dir/src/gmath.c.o" \
"CMakeFiles/nmea.dir/src/info.c.o" \
"CMakeFiles/nmea.dir/src/parse.c.o" \
"CMakeFiles/nmea.dir/src/parser.c.o" \
"CMakeFiles/nmea.dir/src/sentence.c.o" \
"CMakeFiles/nmea.dir/src/time.c.o" \
"CMakeFiles/nmea.dir/src/tok.c.o"

# External object files for target nmea
nmea_EXTERNAL_OBJECTS =

lib/nmealib/libnmea.a: lib/nmealib/CMakeFiles/nmea.dir/src/context.c.o
lib/nmealib/libnmea.a: lib/nmealib/CMakeFiles/nmea.dir/src/generate.c.o
lib/nmealib/libnmea.a: lib/nmealib/CMakeFiles/nmea.dir/src/generator.c.o
lib/nmealib/libnmea.a: lib/nmealib/CMakeFiles/nmea.dir/src/gmath.c.o
lib/nmealib/libnmea.a: lib/nmealib/CMakeFiles/nmea.dir/src/info.c.o
lib/nmealib/libnmea.a: lib/nmealib/CMakeFiles/nmea.dir/src/parse.c.o
lib/nmealib/libnmea.a: lib/nmealib/CMakeFiles/nmea.dir/src/parser.c.o
lib/nmealib/libnmea.a: lib/nmealib/CMakeFiles/nmea.dir/src/sentence.c.o
lib/nmealib/libnmea.a: lib/nmealib/CMakeFiles/nmea.dir/src/time.c.o
lib/nmealib/libnmea.a: lib/nmealib/CMakeFiles/nmea.dir/src/tok.c.o
lib/nmealib/libnmea.a: lib/nmealib/CMakeFiles/nmea.dir/build.make
lib/nmealib/libnmea.a: lib/nmealib/CMakeFiles/nmea.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qigao/qigao/linux_learn/manager/LowerComp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C static library libnmea.a"
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && $(CMAKE_COMMAND) -P CMakeFiles/nmea.dir/cmake_clean_target.cmake
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nmea.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/nmealib/CMakeFiles/nmea.dir/build: lib/nmealib/libnmea.a

.PHONY : lib/nmealib/CMakeFiles/nmea.dir/build

lib/nmealib/CMakeFiles/nmea.dir/clean:
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib && $(CMAKE_COMMAND) -P CMakeFiles/nmea.dir/cmake_clean.cmake
.PHONY : lib/nmealib/CMakeFiles/nmea.dir/clean

lib/nmealib/CMakeFiles/nmea.dir/depend:
	cd /home/qigao/qigao/linux_learn/manager/LowerComp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qigao/qigao/linux_learn/manager/LowerComp /home/qigao/qigao/linux_learn/manager/LowerComp/lib/nmealib /home/qigao/qigao/linux_learn/manager/LowerComp/build /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib /home/qigao/qigao/linux_learn/manager/LowerComp/build/lib/nmealib/CMakeFiles/nmea.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/nmealib/CMakeFiles/nmea.dir/depend
