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
CMAKE_SOURCE_DIR = /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build

# Include any dependencies generated for this target.
include extern/vanetza/vanetza/net/CMakeFiles/net.dir/depend.make

# Include the progress variables for this target.
include extern/vanetza/vanetza/net/CMakeFiles/net.dir/progress.make

# Include the compile flags for this target's objects.
include extern/vanetza/vanetza/net/CMakeFiles/net.dir/flags.make

extern/vanetza/vanetza/net/CMakeFiles/net.dir/buffer_packet.cpp.o: extern/vanetza/vanetza/net/CMakeFiles/net.dir/flags.make
extern/vanetza/vanetza/net/CMakeFiles/net.dir/buffer_packet.cpp.o: ../extern/vanetza/vanetza/net/buffer_packet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object extern/vanetza/vanetza/net/CMakeFiles/net.dir/buffer_packet.cpp.o"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/net.dir/buffer_packet.cpp.o -c /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/buffer_packet.cpp

extern/vanetza/vanetza/net/CMakeFiles/net.dir/buffer_packet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/net.dir/buffer_packet.cpp.i"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/buffer_packet.cpp > CMakeFiles/net.dir/buffer_packet.cpp.i

extern/vanetza/vanetza/net/CMakeFiles/net.dir/buffer_packet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/net.dir/buffer_packet.cpp.s"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/buffer_packet.cpp -o CMakeFiles/net.dir/buffer_packet.cpp.s

extern/vanetza/vanetza/net/CMakeFiles/net.dir/chunk_packet.cpp.o: extern/vanetza/vanetza/net/CMakeFiles/net.dir/flags.make
extern/vanetza/vanetza/net/CMakeFiles/net.dir/chunk_packet.cpp.o: ../extern/vanetza/vanetza/net/chunk_packet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object extern/vanetza/vanetza/net/CMakeFiles/net.dir/chunk_packet.cpp.o"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/net.dir/chunk_packet.cpp.o -c /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/chunk_packet.cpp

extern/vanetza/vanetza/net/CMakeFiles/net.dir/chunk_packet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/net.dir/chunk_packet.cpp.i"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/chunk_packet.cpp > CMakeFiles/net.dir/chunk_packet.cpp.i

extern/vanetza/vanetza/net/CMakeFiles/net.dir/chunk_packet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/net.dir/chunk_packet.cpp.s"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/chunk_packet.cpp -o CMakeFiles/net.dir/chunk_packet.cpp.s

extern/vanetza/vanetza/net/CMakeFiles/net.dir/cohesive_packet.cpp.o: extern/vanetza/vanetza/net/CMakeFiles/net.dir/flags.make
extern/vanetza/vanetza/net/CMakeFiles/net.dir/cohesive_packet.cpp.o: ../extern/vanetza/vanetza/net/cohesive_packet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object extern/vanetza/vanetza/net/CMakeFiles/net.dir/cohesive_packet.cpp.o"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/net.dir/cohesive_packet.cpp.o -c /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/cohesive_packet.cpp

extern/vanetza/vanetza/net/CMakeFiles/net.dir/cohesive_packet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/net.dir/cohesive_packet.cpp.i"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/cohesive_packet.cpp > CMakeFiles/net.dir/cohesive_packet.cpp.i

extern/vanetza/vanetza/net/CMakeFiles/net.dir/cohesive_packet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/net.dir/cohesive_packet.cpp.s"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/cohesive_packet.cpp -o CMakeFiles/net.dir/cohesive_packet.cpp.s

extern/vanetza/vanetza/net/CMakeFiles/net.dir/ethernet_header.cpp.o: extern/vanetza/vanetza/net/CMakeFiles/net.dir/flags.make
extern/vanetza/vanetza/net/CMakeFiles/net.dir/ethernet_header.cpp.o: ../extern/vanetza/vanetza/net/ethernet_header.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object extern/vanetza/vanetza/net/CMakeFiles/net.dir/ethernet_header.cpp.o"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/net.dir/ethernet_header.cpp.o -c /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/ethernet_header.cpp

extern/vanetza/vanetza/net/CMakeFiles/net.dir/ethernet_header.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/net.dir/ethernet_header.cpp.i"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/ethernet_header.cpp > CMakeFiles/net.dir/ethernet_header.cpp.i

extern/vanetza/vanetza/net/CMakeFiles/net.dir/ethernet_header.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/net.dir/ethernet_header.cpp.s"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/ethernet_header.cpp -o CMakeFiles/net.dir/ethernet_header.cpp.s

extern/vanetza/vanetza/net/CMakeFiles/net.dir/mac_address.cpp.o: extern/vanetza/vanetza/net/CMakeFiles/net.dir/flags.make
extern/vanetza/vanetza/net/CMakeFiles/net.dir/mac_address.cpp.o: ../extern/vanetza/vanetza/net/mac_address.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object extern/vanetza/vanetza/net/CMakeFiles/net.dir/mac_address.cpp.o"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/net.dir/mac_address.cpp.o -c /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/mac_address.cpp

extern/vanetza/vanetza/net/CMakeFiles/net.dir/mac_address.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/net.dir/mac_address.cpp.i"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/mac_address.cpp > CMakeFiles/net.dir/mac_address.cpp.i

extern/vanetza/vanetza/net/CMakeFiles/net.dir/mac_address.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/net.dir/mac_address.cpp.s"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/mac_address.cpp -o CMakeFiles/net.dir/mac_address.cpp.s

extern/vanetza/vanetza/net/CMakeFiles/net.dir/packet_variant.cpp.o: extern/vanetza/vanetza/net/CMakeFiles/net.dir/flags.make
extern/vanetza/vanetza/net/CMakeFiles/net.dir/packet_variant.cpp.o: ../extern/vanetza/vanetza/net/packet_variant.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object extern/vanetza/vanetza/net/CMakeFiles/net.dir/packet_variant.cpp.o"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/net.dir/packet_variant.cpp.o -c /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/packet_variant.cpp

extern/vanetza/vanetza/net/CMakeFiles/net.dir/packet_variant.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/net.dir/packet_variant.cpp.i"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/packet_variant.cpp > CMakeFiles/net.dir/packet_variant.cpp.i

extern/vanetza/vanetza/net/CMakeFiles/net.dir/packet_variant.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/net.dir/packet_variant.cpp.s"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/packet_variant.cpp -o CMakeFiles/net.dir/packet_variant.cpp.s

extern/vanetza/vanetza/net/CMakeFiles/net.dir/packet.cpp.o: extern/vanetza/vanetza/net/CMakeFiles/net.dir/flags.make
extern/vanetza/vanetza/net/CMakeFiles/net.dir/packet.cpp.o: ../extern/vanetza/vanetza/net/packet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object extern/vanetza/vanetza/net/CMakeFiles/net.dir/packet.cpp.o"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/net.dir/packet.cpp.o -c /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/packet.cpp

extern/vanetza/vanetza/net/CMakeFiles/net.dir/packet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/net.dir/packet.cpp.i"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/packet.cpp > CMakeFiles/net.dir/packet.cpp.i

extern/vanetza/vanetza/net/CMakeFiles/net.dir/packet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/net.dir/packet.cpp.s"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/packet.cpp -o CMakeFiles/net.dir/packet.cpp.s

extern/vanetza/vanetza/net/CMakeFiles/net.dir/proxy_header.cpp.o: extern/vanetza/vanetza/net/CMakeFiles/net.dir/flags.make
extern/vanetza/vanetza/net/CMakeFiles/net.dir/proxy_header.cpp.o: ../extern/vanetza/vanetza/net/proxy_header.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object extern/vanetza/vanetza/net/CMakeFiles/net.dir/proxy_header.cpp.o"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/net.dir/proxy_header.cpp.o -c /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/proxy_header.cpp

extern/vanetza/vanetza/net/CMakeFiles/net.dir/proxy_header.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/net.dir/proxy_header.cpp.i"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/proxy_header.cpp > CMakeFiles/net.dir/proxy_header.cpp.i

extern/vanetza/vanetza/net/CMakeFiles/net.dir/proxy_header.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/net.dir/proxy_header.cpp.s"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/proxy_header.cpp -o CMakeFiles/net.dir/proxy_header.cpp.s

extern/vanetza/vanetza/net/CMakeFiles/net.dir/io_vector.cpp.o: extern/vanetza/vanetza/net/CMakeFiles/net.dir/flags.make
extern/vanetza/vanetza/net/CMakeFiles/net.dir/io_vector.cpp.o: ../extern/vanetza/vanetza/net/io_vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object extern/vanetza/vanetza/net/CMakeFiles/net.dir/io_vector.cpp.o"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/net.dir/io_vector.cpp.o -c /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/io_vector.cpp

extern/vanetza/vanetza/net/CMakeFiles/net.dir/io_vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/net.dir/io_vector.cpp.i"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/io_vector.cpp > CMakeFiles/net.dir/io_vector.cpp.i

extern/vanetza/vanetza/net/CMakeFiles/net.dir/io_vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/net.dir/io_vector.cpp.s"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/io_vector.cpp -o CMakeFiles/net.dir/io_vector.cpp.s

extern/vanetza/vanetza/net/CMakeFiles/net.dir/sockaddr.cpp.o: extern/vanetza/vanetza/net/CMakeFiles/net.dir/flags.make
extern/vanetza/vanetza/net/CMakeFiles/net.dir/sockaddr.cpp.o: ../extern/vanetza/vanetza/net/sockaddr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object extern/vanetza/vanetza/net/CMakeFiles/net.dir/sockaddr.cpp.o"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/net.dir/sockaddr.cpp.o -c /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/sockaddr.cpp

extern/vanetza/vanetza/net/CMakeFiles/net.dir/sockaddr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/net.dir/sockaddr.cpp.i"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/sockaddr.cpp > CMakeFiles/net.dir/sockaddr.cpp.i

extern/vanetza/vanetza/net/CMakeFiles/net.dir/sockaddr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/net.dir/sockaddr.cpp.s"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net/sockaddr.cpp -o CMakeFiles/net.dir/sockaddr.cpp.s

# Object files for target net
net_OBJECTS = \
"CMakeFiles/net.dir/buffer_packet.cpp.o" \
"CMakeFiles/net.dir/chunk_packet.cpp.o" \
"CMakeFiles/net.dir/cohesive_packet.cpp.o" \
"CMakeFiles/net.dir/ethernet_header.cpp.o" \
"CMakeFiles/net.dir/mac_address.cpp.o" \
"CMakeFiles/net.dir/packet_variant.cpp.o" \
"CMakeFiles/net.dir/packet.cpp.o" \
"CMakeFiles/net.dir/proxy_header.cpp.o" \
"CMakeFiles/net.dir/io_vector.cpp.o" \
"CMakeFiles/net.dir/sockaddr.cpp.o"

# External object files for target net
net_EXTERNAL_OBJECTS =

extern/vanetza/lib/libvanetza_net.so: extern/vanetza/vanetza/net/CMakeFiles/net.dir/buffer_packet.cpp.o
extern/vanetza/lib/libvanetza_net.so: extern/vanetza/vanetza/net/CMakeFiles/net.dir/chunk_packet.cpp.o
extern/vanetza/lib/libvanetza_net.so: extern/vanetza/vanetza/net/CMakeFiles/net.dir/cohesive_packet.cpp.o
extern/vanetza/lib/libvanetza_net.so: extern/vanetza/vanetza/net/CMakeFiles/net.dir/ethernet_header.cpp.o
extern/vanetza/lib/libvanetza_net.so: extern/vanetza/vanetza/net/CMakeFiles/net.dir/mac_address.cpp.o
extern/vanetza/lib/libvanetza_net.so: extern/vanetza/vanetza/net/CMakeFiles/net.dir/packet_variant.cpp.o
extern/vanetza/lib/libvanetza_net.so: extern/vanetza/vanetza/net/CMakeFiles/net.dir/packet.cpp.o
extern/vanetza/lib/libvanetza_net.so: extern/vanetza/vanetza/net/CMakeFiles/net.dir/proxy_header.cpp.o
extern/vanetza/lib/libvanetza_net.so: extern/vanetza/vanetza/net/CMakeFiles/net.dir/io_vector.cpp.o
extern/vanetza/lib/libvanetza_net.so: extern/vanetza/vanetza/net/CMakeFiles/net.dir/sockaddr.cpp.o
extern/vanetza/lib/libvanetza_net.so: extern/vanetza/vanetza/net/CMakeFiles/net.dir/build.make
extern/vanetza/lib/libvanetza_net.so: extern/vanetza/lib/libvanetza_common.so
extern/vanetza/lib/libvanetza_net.so: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
extern/vanetza/lib/libvanetza_net.so: extern/vanetza/vanetza/net/CMakeFiles/net.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX shared library ../../lib/libvanetza_net.so"
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/net.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
extern/vanetza/vanetza/net/CMakeFiles/net.dir/build: extern/vanetza/lib/libvanetza_net.so

.PHONY : extern/vanetza/vanetza/net/CMakeFiles/net.dir/build

extern/vanetza/vanetza/net/CMakeFiles/net.dir/clean:
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net && $(CMAKE_COMMAND) -P CMakeFiles/net.dir/cmake_clean.cmake
.PHONY : extern/vanetza/vanetza/net/CMakeFiles/net.dir/clean

extern/vanetza/vanetza/net/CMakeFiles/net.dir/depend:
	cd /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/extern/vanetza/vanetza/net /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net /home/llagus/Documents/TELECOS/Pràctiques/I2cat/artery_llagus/build/extern/vanetza/vanetza/net/CMakeFiles/net.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : extern/vanetza/vanetza/net/CMakeFiles/net.dir/depend

