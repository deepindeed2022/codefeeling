CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
project(CmakeTestFindPackage)

SET(CMAKE_BUILD_TYPE Debug CACHE STRING "cmake build type (Release|Debug)")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

find_package(ClimbingStats REQUIRED
    PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../createpackage/build/ClimbingStats)

    
add_executable(findpackagetest main.cpp)
string(TOLOWER ${CMAKE_BUILD_TYPE} _type)
if (_type STREQUAL debug)
    target_compile_definitions(findpackagetest PRIVATE DEBUG_BUILD)
endif()

target_link_libraries(findpackagetest Codefeeling::ClimbingStats)