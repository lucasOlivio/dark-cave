# cmake version to be used
cmake_minimum_required( VERSION 3.22.1 )

# project name
project( DarkCave )

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Add executable
add_executable(DarkCave ${SOURCES} main.cpp)

# Set output directory
set_target_properties(DarkCave PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")

# Set executable name
set_target_properties(DarkCave PROPERTIES OUTPUT_NAME "DarkCave")