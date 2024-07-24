cmake_minimum_required(VERSION 3.0.0)
project(fun VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(fun fun.cpp)
target_compile_options(fun PRIVATE -Wall -Werror -Wextra -pedantic -std=c++17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
