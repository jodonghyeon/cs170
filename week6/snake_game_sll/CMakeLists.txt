cmake_minimum_required(VERSION 3.11.0)

project(snake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCE_CODE
    include/Constants.h
    source/SnakeSegment.cpp include/SnakeSegment.h
    source/SnakeGame.cpp include/SnakeGame.h
    source/main.cpp
)

add_executable(snakegame ${SOURCE_CODE})

include(FetchContent)
set(RAYLIB_VERSION 4.5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
  FetchContent_MakeAvailable(raylib)
endif()

if(MSVC)
	target_compile_options(snakegame PRIVATE /W4 /WX)
else()
	target_compile_options(snakegame PRIVATE -Wall -Werror -Wextra -pedantic)
endif()

target_include_directories(snakegame PRIVATE include)
target_include_directories(snakegame PRIVATE source)
target_link_directories(snakegame PRIVATE raylib)