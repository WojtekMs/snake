# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/build

# Include any dependencies generated for this target.
include CMakeFiles/a.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/a.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a.out.dir/flags.make

CMakeFiles/a.out.dir/main.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/a.out.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/main.cpp.o -c /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/main.cpp

CMakeFiles/a.out.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/main.cpp > CMakeFiles/a.out.dir/main.cpp.i

CMakeFiles/a.out.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/main.cpp -o CMakeFiles/a.out.dir/main.cpp.s

CMakeFiles/a.out.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/a.out.dir/main.cpp.o.requires

CMakeFiles/a.out.dir/main.cpp.o.provides: CMakeFiles/a.out.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.dir/main.cpp.o.provides

CMakeFiles/a.out.dir/main.cpp.o.provides.build: CMakeFiles/a.out.dir/main.cpp.o


CMakeFiles/a.out.dir/SnakeBoard.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/SnakeBoard.cpp.o: ../SnakeBoard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/a.out.dir/SnakeBoard.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/SnakeBoard.cpp.o -c /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/SnakeBoard.cpp

CMakeFiles/a.out.dir/SnakeBoard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/SnakeBoard.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/SnakeBoard.cpp > CMakeFiles/a.out.dir/SnakeBoard.cpp.i

CMakeFiles/a.out.dir/SnakeBoard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/SnakeBoard.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/SnakeBoard.cpp -o CMakeFiles/a.out.dir/SnakeBoard.cpp.s

CMakeFiles/a.out.dir/SnakeBoard.cpp.o.requires:

.PHONY : CMakeFiles/a.out.dir/SnakeBoard.cpp.o.requires

CMakeFiles/a.out.dir/SnakeBoard.cpp.o.provides: CMakeFiles/a.out.dir/SnakeBoard.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/SnakeBoard.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.dir/SnakeBoard.cpp.o.provides

CMakeFiles/a.out.dir/SnakeBoard.cpp.o.provides.build: CMakeFiles/a.out.dir/SnakeBoard.cpp.o


CMakeFiles/a.out.dir/Snake.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/Snake.cpp.o: ../Snake.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/a.out.dir/Snake.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/Snake.cpp.o -c /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/Snake.cpp

CMakeFiles/a.out.dir/Snake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/Snake.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/Snake.cpp > CMakeFiles/a.out.dir/Snake.cpp.i

CMakeFiles/a.out.dir/Snake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/Snake.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/Snake.cpp -o CMakeFiles/a.out.dir/Snake.cpp.s

CMakeFiles/a.out.dir/Snake.cpp.o.requires:

.PHONY : CMakeFiles/a.out.dir/Snake.cpp.o.requires

CMakeFiles/a.out.dir/Snake.cpp.o.provides: CMakeFiles/a.out.dir/Snake.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/Snake.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.dir/Snake.cpp.o.provides

CMakeFiles/a.out.dir/Snake.cpp.o.provides.build: CMakeFiles/a.out.dir/Snake.cpp.o


CMakeFiles/a.out.dir/Debug_view.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/Debug_view.cpp.o: ../Debug_view.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/a.out.dir/Debug_view.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/Debug_view.cpp.o -c /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/Debug_view.cpp

CMakeFiles/a.out.dir/Debug_view.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/Debug_view.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/Debug_view.cpp > CMakeFiles/a.out.dir/Debug_view.cpp.i

CMakeFiles/a.out.dir/Debug_view.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/Debug_view.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/Debug_view.cpp -o CMakeFiles/a.out.dir/Debug_view.cpp.s

CMakeFiles/a.out.dir/Debug_view.cpp.o.requires:

.PHONY : CMakeFiles/a.out.dir/Debug_view.cpp.o.requires

CMakeFiles/a.out.dir/Debug_view.cpp.o.provides: CMakeFiles/a.out.dir/Debug_view.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/Debug_view.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.dir/Debug_view.cpp.o.provides

CMakeFiles/a.out.dir/Debug_view.cpp.o.provides.build: CMakeFiles/a.out.dir/Debug_view.cpp.o


CMakeFiles/a.out.dir/SFMLView.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/SFMLView.cpp.o: ../SFMLView.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/a.out.dir/SFMLView.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/SFMLView.cpp.o -c /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/SFMLView.cpp

CMakeFiles/a.out.dir/SFMLView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/SFMLView.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/SFMLView.cpp > CMakeFiles/a.out.dir/SFMLView.cpp.i

CMakeFiles/a.out.dir/SFMLView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/SFMLView.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/SFMLView.cpp -o CMakeFiles/a.out.dir/SFMLView.cpp.s

CMakeFiles/a.out.dir/SFMLView.cpp.o.requires:

.PHONY : CMakeFiles/a.out.dir/SFMLView.cpp.o.requires

CMakeFiles/a.out.dir/SFMLView.cpp.o.provides: CMakeFiles/a.out.dir/SFMLView.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/SFMLView.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.dir/SFMLView.cpp.o.provides

CMakeFiles/a.out.dir/SFMLView.cpp.o.provides.build: CMakeFiles/a.out.dir/SFMLView.cpp.o


CMakeFiles/a.out.dir/SFMLController.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/SFMLController.cpp.o: ../SFMLController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/a.out.dir/SFMLController.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/SFMLController.cpp.o -c /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/SFMLController.cpp

CMakeFiles/a.out.dir/SFMLController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/SFMLController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/SFMLController.cpp > CMakeFiles/a.out.dir/SFMLController.cpp.i

CMakeFiles/a.out.dir/SFMLController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/SFMLController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/SFMLController.cpp -o CMakeFiles/a.out.dir/SFMLController.cpp.s

CMakeFiles/a.out.dir/SFMLController.cpp.o.requires:

.PHONY : CMakeFiles/a.out.dir/SFMLController.cpp.o.requires

CMakeFiles/a.out.dir/SFMLController.cpp.o.provides: CMakeFiles/a.out.dir/SFMLController.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/SFMLController.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.dir/SFMLController.cpp.o.provides

CMakeFiles/a.out.dir/SFMLController.cpp.o.provides.build: CMakeFiles/a.out.dir/SFMLController.cpp.o


CMakeFiles/a.out.dir/tests.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/tests.cpp.o: ../tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/a.out.dir/tests.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/tests.cpp.o -c /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/tests.cpp

CMakeFiles/a.out.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/tests.cpp > CMakeFiles/a.out.dir/tests.cpp.i

CMakeFiles/a.out.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/tests.cpp -o CMakeFiles/a.out.dir/tests.cpp.s

CMakeFiles/a.out.dir/tests.cpp.o.requires:

.PHONY : CMakeFiles/a.out.dir/tests.cpp.o.requires

CMakeFiles/a.out.dir/tests.cpp.o.provides: CMakeFiles/a.out.dir/tests.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/tests.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.dir/tests.cpp.o.provides

CMakeFiles/a.out.dir/tests.cpp.o.provides.build: CMakeFiles/a.out.dir/tests.cpp.o


# Object files for target a.out
a_out_OBJECTS = \
"CMakeFiles/a.out.dir/main.cpp.o" \
"CMakeFiles/a.out.dir/SnakeBoard.cpp.o" \
"CMakeFiles/a.out.dir/Snake.cpp.o" \
"CMakeFiles/a.out.dir/Debug_view.cpp.o" \
"CMakeFiles/a.out.dir/SFMLView.cpp.o" \
"CMakeFiles/a.out.dir/SFMLController.cpp.o" \
"CMakeFiles/a.out.dir/tests.cpp.o"

# External object files for target a.out
a_out_EXTERNAL_OBJECTS =

../a.out: CMakeFiles/a.out.dir/main.cpp.o
../a.out: CMakeFiles/a.out.dir/SnakeBoard.cpp.o
../a.out: CMakeFiles/a.out.dir/Snake.cpp.o
../a.out: CMakeFiles/a.out.dir/Debug_view.cpp.o
../a.out: CMakeFiles/a.out.dir/SFMLView.cpp.o
../a.out: CMakeFiles/a.out.dir/SFMLController.cpp.o
../a.out: CMakeFiles/a.out.dir/tests.cpp.o
../a.out: CMakeFiles/a.out.dir/build.make
../a.out: CMakeFiles/a.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ../a.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/a.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a.out.dir/build: ../a.out

.PHONY : CMakeFiles/a.out.dir/build

CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/main.cpp.o.requires
CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/SnakeBoard.cpp.o.requires
CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/Snake.cpp.o.requires
CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/Debug_view.cpp.o.requires
CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/SFMLView.cpp.o.requires
CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/SFMLController.cpp.o.requires
CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/tests.cpp.o.requires

.PHONY : CMakeFiles/a.out.dir/requires

CMakeFiles/a.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/a.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/a.out.dir/clean

CMakeFiles/a.out.dir/depend:
	cd /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/build /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/build /home/wojtek/cpp/Programowanie/Obiektowe/Studia_projekt/snake/build/CMakeFiles/a.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a.out.dir/depend
