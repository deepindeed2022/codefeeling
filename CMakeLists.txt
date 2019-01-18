
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(practise)

if (${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
    if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
        SET(NEWCXX_ENABLED_FLAG "-std=c++11 -stdlib=libc++ -Wall -O2")
    else()
        SET(NEWCXX_ENABLED_FLAG "-std=c++11 -Wall -Wno-mismatched-tags -O2")
    endif()
elseif (${CMAKE_CXX_COMPILER_ID} MATCHES "GNU")
    SET(NEWCXX_ENABLED_FLAG "-std=c++11 -Wall")
else()
    MESSAGE(FATAL_ERROR, "Only GCC and clang is supported for now.")
endif()

SET(CMAKE_CXX_FLAGS ${NEWCXX_ENABLED_FLAG})
MESSAGE(STATUS "CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/gtest/include
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/gtest)

SET(GTEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/gtest/src/gtest-all.cc)
ADD_LIBRARY(gtest ${GTEST_SRC})


