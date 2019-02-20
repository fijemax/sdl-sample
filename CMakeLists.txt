cmake_minimum_required (VERSION 2.6)
project (SDLTest)

# The version number.
set (SDLTest_VERSION_MAJOR 1)
set (SDLTest_VERSION_MINOR 18)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/include/util/SDLTestConfig.h.in"
  "${PROJECT_BINARY_DIR}/include/util/SDLTestConfig.h"
  )

# SDL libraries
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

# Box2D libraries
find_package(Box2D REQUIRED)
include_directories(${BOX2D_INCLUDE_DIRS})

# Source project
file(GLOB ProjectSourceGlob
          src/core/*.cpp
          src/util/*.cpp
          src/node/*.cpp
          src/graphic/*.cpp
          src/pysical/*.cpp)
add_library(Core ${ProjectSourceGlob})
include_directories ("${CMAKE_CURRENT_BINARY_DIR}/include")
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/include")

# Resource
file(GLOB AssetsGlob assets/*)

# SDL-Test
add_executable(SDL-Test main.cpp)
target_link_libraries(SDL-Test Core)
target_link_libraries(SDL-Test ${SDL2_LIBRARIES})
target_link_libraries(SDL-Test ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(SDL-Test ${BOX2D_LIBRARIES})

# Install
install(FILES ${AssetsGlob} DESTINATION assets)
install(FILES ${CoreGlob} DESTINATION include)
install(TARGETS SDL-Test DESTINATION bin)
install(TARGETS Core DESTINATION lib)