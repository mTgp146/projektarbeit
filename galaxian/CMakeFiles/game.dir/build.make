# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/game.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/main_controller.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/main_controller.cpp.o: main_controller.cpp
CMakeFiles/game.dir/main_controller.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/main_controller.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/main_controller.cpp.o -MF CMakeFiles/game.dir/main_controller.cpp.o.d -o CMakeFiles/game.dir/main_controller.cpp.o -c /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/main_controller.cpp

CMakeFiles/game.dir/main_controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/main_controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/main_controller.cpp > CMakeFiles/game.dir/main_controller.cpp.i

CMakeFiles/game.dir/main_controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/main_controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/main_controller.cpp -o CMakeFiles/game.dir/main_controller.cpp.s

CMakeFiles/game.dir/view.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/view.cpp.o: view.cpp
CMakeFiles/game.dir/view.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game.dir/view.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/view.cpp.o -MF CMakeFiles/game.dir/view.cpp.o.d -o CMakeFiles/game.dir/view.cpp.o -c /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/view.cpp

CMakeFiles/game.dir/view.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/view.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/view.cpp > CMakeFiles/game.dir/view.cpp.i

CMakeFiles/game.dir/view.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/view.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/view.cpp -o CMakeFiles/game.dir/view.cpp.s

CMakeFiles/game.dir/controller.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/controller.cpp.o: controller.cpp
CMakeFiles/game.dir/controller.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/game.dir/controller.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/controller.cpp.o -MF CMakeFiles/game.dir/controller.cpp.o.d -o CMakeFiles/game.dir/controller.cpp.o -c /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/controller.cpp

CMakeFiles/game.dir/controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/controller.cpp > CMakeFiles/game.dir/controller.cpp.i

CMakeFiles/game.dir/controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/controller.cpp -o CMakeFiles/game.dir/controller.cpp.s

CMakeFiles/game.dir/model.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/model.cpp.o: model.cpp
CMakeFiles/game.dir/model.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/game.dir/model.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/model.cpp.o -MF CMakeFiles/game.dir/model.cpp.o.d -o CMakeFiles/game.dir/model.cpp.o -c /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/model.cpp

CMakeFiles/game.dir/model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/model.cpp > CMakeFiles/game.dir/model.cpp.i

CMakeFiles/game.dir/model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/model.cpp -o CMakeFiles/game.dir/model.cpp.s

CMakeFiles/game.dir/models/galaxip.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/models/galaxip.cpp.o: models/galaxip.cpp
CMakeFiles/game.dir/models/galaxip.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/game.dir/models/galaxip.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/models/galaxip.cpp.o -MF CMakeFiles/game.dir/models/galaxip.cpp.o.d -o CMakeFiles/game.dir/models/galaxip.cpp.o -c /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/galaxip.cpp

CMakeFiles/game.dir/models/galaxip.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/models/galaxip.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/galaxip.cpp > CMakeFiles/game.dir/models/galaxip.cpp.i

CMakeFiles/game.dir/models/galaxip.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/models/galaxip.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/galaxip.cpp -o CMakeFiles/game.dir/models/galaxip.cpp.s

CMakeFiles/game.dir/models/projectile.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/models/projectile.cpp.o: models/projectile.cpp
CMakeFiles/game.dir/models/projectile.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/game.dir/models/projectile.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/models/projectile.cpp.o -MF CMakeFiles/game.dir/models/projectile.cpp.o.d -o CMakeFiles/game.dir/models/projectile.cpp.o -c /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/projectile.cpp

CMakeFiles/game.dir/models/projectile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/models/projectile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/projectile.cpp > CMakeFiles/game.dir/models/projectile.cpp.i

CMakeFiles/game.dir/models/projectile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/models/projectile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/projectile.cpp -o CMakeFiles/game.dir/models/projectile.cpp.s

CMakeFiles/game.dir/models/green_alien.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/models/green_alien.cpp.o: models/green_alien.cpp
CMakeFiles/game.dir/models/green_alien.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/game.dir/models/green_alien.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/models/green_alien.cpp.o -MF CMakeFiles/game.dir/models/green_alien.cpp.o.d -o CMakeFiles/game.dir/models/green_alien.cpp.o -c /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/green_alien.cpp

CMakeFiles/game.dir/models/green_alien.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/models/green_alien.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/green_alien.cpp > CMakeFiles/game.dir/models/green_alien.cpp.i

CMakeFiles/game.dir/models/green_alien.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/models/green_alien.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/green_alien.cpp -o CMakeFiles/game.dir/models/green_alien.cpp.s

CMakeFiles/game.dir/models/blue_alien.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/models/blue_alien.cpp.o: models/blue_alien.cpp
CMakeFiles/game.dir/models/blue_alien.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/game.dir/models/blue_alien.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/models/blue_alien.cpp.o -MF CMakeFiles/game.dir/models/blue_alien.cpp.o.d -o CMakeFiles/game.dir/models/blue_alien.cpp.o -c /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/blue_alien.cpp

CMakeFiles/game.dir/models/blue_alien.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/models/blue_alien.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/blue_alien.cpp > CMakeFiles/game.dir/models/blue_alien.cpp.i

CMakeFiles/game.dir/models/blue_alien.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/models/blue_alien.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/blue_alien.cpp -o CMakeFiles/game.dir/models/blue_alien.cpp.s

CMakeFiles/game.dir/models/red_alien.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/models/red_alien.cpp.o: models/red_alien.cpp
CMakeFiles/game.dir/models/red_alien.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/game.dir/models/red_alien.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/models/red_alien.cpp.o -MF CMakeFiles/game.dir/models/red_alien.cpp.o.d -o CMakeFiles/game.dir/models/red_alien.cpp.o -c /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/red_alien.cpp

CMakeFiles/game.dir/models/red_alien.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/models/red_alien.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/red_alien.cpp > CMakeFiles/game.dir/models/red_alien.cpp.i

CMakeFiles/game.dir/models/red_alien.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/models/red_alien.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/red_alien.cpp -o CMakeFiles/game.dir/models/red_alien.cpp.s

CMakeFiles/game.dir/models/flagship.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/models/flagship.cpp.o: models/flagship.cpp
CMakeFiles/game.dir/models/flagship.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/game.dir/models/flagship.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/models/flagship.cpp.o -MF CMakeFiles/game.dir/models/flagship.cpp.o.d -o CMakeFiles/game.dir/models/flagship.cpp.o -c /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/flagship.cpp

CMakeFiles/game.dir/models/flagship.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/models/flagship.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/flagship.cpp > CMakeFiles/game.dir/models/flagship.cpp.i

CMakeFiles/game.dir/models/flagship.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/models/flagship.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/flagship.cpp -o CMakeFiles/game.dir/models/flagship.cpp.s

CMakeFiles/game.dir/models/alien.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/models/alien.cpp.o: models/alien.cpp
CMakeFiles/game.dir/models/alien.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/game.dir/models/alien.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/models/alien.cpp.o -MF CMakeFiles/game.dir/models/alien.cpp.o.d -o CMakeFiles/game.dir/models/alien.cpp.o -c /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/alien.cpp

CMakeFiles/game.dir/models/alien.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/models/alien.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/alien.cpp > CMakeFiles/game.dir/models/alien.cpp.i

CMakeFiles/game.dir/models/alien.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/models/alien.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/alien.cpp -o CMakeFiles/game.dir/models/alien.cpp.s

CMakeFiles/game.dir/models/background.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/models/background.cpp.o: models/background.cpp
CMakeFiles/game.dir/models/background.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/game.dir/models/background.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/models/background.cpp.o -MF CMakeFiles/game.dir/models/background.cpp.o.d -o CMakeFiles/game.dir/models/background.cpp.o -c /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/background.cpp

CMakeFiles/game.dir/models/background.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/models/background.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/background.cpp > CMakeFiles/game.dir/models/background.cpp.i

CMakeFiles/game.dir/models/background.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/models/background.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/background.cpp -o CMakeFiles/game.dir/models/background.cpp.s

CMakeFiles/game.dir/models/backgroundParticle.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/models/backgroundParticle.cpp.o: models/backgroundParticle.cpp
CMakeFiles/game.dir/models/backgroundParticle.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/game.dir/models/backgroundParticle.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/models/backgroundParticle.cpp.o -MF CMakeFiles/game.dir/models/backgroundParticle.cpp.o.d -o CMakeFiles/game.dir/models/backgroundParticle.cpp.o -c /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/backgroundParticle.cpp

CMakeFiles/game.dir/models/backgroundParticle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/models/backgroundParticle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/backgroundParticle.cpp > CMakeFiles/game.dir/models/backgroundParticle.cpp.i

CMakeFiles/game.dir/models/backgroundParticle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/models/backgroundParticle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/backgroundParticle.cpp -o CMakeFiles/game.dir/models/backgroundParticle.cpp.s

CMakeFiles/game.dir/models/sounds.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/models/sounds.cpp.o: models/sounds.cpp
CMakeFiles/game.dir/models/sounds.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/game.dir/models/sounds.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/models/sounds.cpp.o -MF CMakeFiles/game.dir/models/sounds.cpp.o.d -o CMakeFiles/game.dir/models/sounds.cpp.o -c /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/sounds.cpp

CMakeFiles/game.dir/models/sounds.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/models/sounds.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/sounds.cpp > CMakeFiles/game.dir/models/sounds.cpp.i

CMakeFiles/game.dir/models/sounds.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/models/sounds.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/sounds.cpp -o CMakeFiles/game.dir/models/sounds.cpp.s

CMakeFiles/game.dir/models/points.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/models/points.cpp.o: models/points.cpp
CMakeFiles/game.dir/models/points.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/game.dir/models/points.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/models/points.cpp.o -MF CMakeFiles/game.dir/models/points.cpp.o.d -o CMakeFiles/game.dir/models/points.cpp.o -c /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/points.cpp

CMakeFiles/game.dir/models/points.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/models/points.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/points.cpp > CMakeFiles/game.dir/models/points.cpp.i

CMakeFiles/game.dir/models/points.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/models/points.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/models/points.cpp -o CMakeFiles/game.dir/models/points.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/main_controller.cpp.o" \
"CMakeFiles/game.dir/view.cpp.o" \
"CMakeFiles/game.dir/controller.cpp.o" \
"CMakeFiles/game.dir/model.cpp.o" \
"CMakeFiles/game.dir/models/galaxip.cpp.o" \
"CMakeFiles/game.dir/models/projectile.cpp.o" \
"CMakeFiles/game.dir/models/green_alien.cpp.o" \
"CMakeFiles/game.dir/models/blue_alien.cpp.o" \
"CMakeFiles/game.dir/models/red_alien.cpp.o" \
"CMakeFiles/game.dir/models/flagship.cpp.o" \
"CMakeFiles/game.dir/models/alien.cpp.o" \
"CMakeFiles/game.dir/models/background.cpp.o" \
"CMakeFiles/game.dir/models/backgroundParticle.cpp.o" \
"CMakeFiles/game.dir/models/sounds.cpp.o" \
"CMakeFiles/game.dir/models/points.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

game: CMakeFiles/game.dir/main_controller.cpp.o
game: CMakeFiles/game.dir/view.cpp.o
game: CMakeFiles/game.dir/controller.cpp.o
game: CMakeFiles/game.dir/model.cpp.o
game: CMakeFiles/game.dir/models/galaxip.cpp.o
game: CMakeFiles/game.dir/models/projectile.cpp.o
game: CMakeFiles/game.dir/models/green_alien.cpp.o
game: CMakeFiles/game.dir/models/blue_alien.cpp.o
game: CMakeFiles/game.dir/models/red_alien.cpp.o
game: CMakeFiles/game.dir/models/flagship.cpp.o
game: CMakeFiles/game.dir/models/alien.cpp.o
game: CMakeFiles/game.dir/models/background.cpp.o
game: CMakeFiles/game.dir/models/backgroundParticle.cpp.o
game: CMakeFiles/game.dir/models/sounds.cpp.o
game: CMakeFiles/game.dir/models/points.cpp.o
game: CMakeFiles/game.dir/build.make
game: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game
.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	cd /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian /home/computergrafik/Desktop/project/projektarbeit/projektarbeit/galaxian/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend
