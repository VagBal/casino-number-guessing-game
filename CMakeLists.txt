cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CasinoNumberGuessingGame)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Enable verbose output
set(CMAKE_VERBOSE_MAKEFILE ON)

# Update the path to main.cpp if necessary
if(NOT EXISTS "${CMAKE_SOURCE_DIR}/src/main.cpp")
  message(FATAL_ERROR "main.cpp not found in ${CMAKE_SOURCE_DIR}/src")
endif()

# Add the executable
add_executable(CasinoNumberGuessingGame 
  src/main.cpp 
  src/Game.cpp 
  src/Player.cpp
)
