cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

project(PolymorphicPlayer VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CompilerWarnings.cmake)
add_library(project_options INTERFACE)
set_target_properties(project_options PROPERTIES
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
target_compile_features(project_options INTERFACE cxx_std_17)
set_project_warnings(project_options)

set(SOURCE
    source/PRNG.h           source/PRNG.cpp
    source/Player.h         source/Player.cpp
    source/PlayerList.h     source/PlayerList.cpp
    source/Pyro.h           source/Pyro.cpp
    source/Scout.h          source/Scout.cpp
    source/Soldier.h        source/Soldier.cpp
    source/Team.h           source/Team.cpp
    source/SubscriptError.h
    source/driver.cpp
)

add_executable(driver ${SOURCE})
target_link_libraries(driver PRIVATE project_options)
target_compile_definitions(driver PRIVATE TESTALL)

add_custom_target(copy_files ALL
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/BlueTeam.txt ${CMAKE_CURRENT_BINARY_DIR}/BlueTeam.txt
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/RedTeam.txt ${CMAKE_CURRENT_BINARY_DIR}/RedTeam.txt
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/Team1.txt ${CMAKE_CURRENT_BINARY_DIR}/Team1.txt
    DEPENDS driver
)

