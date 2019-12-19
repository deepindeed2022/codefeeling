CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
project(CodefeelingCmakeTest)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

set(Codefeeling_VERSION 1.0.1)

include(GenerateExportHeader)

add_library(ClimbingStats SHARED climbingstats.cpp)
generate_export_header(ClimbingStats)
set_property(TARGET ClimbingStats PROPERTY VERSION ${Codefeeling_VERSION})
set_property(TARGET ClimbingStats PROPERTY SOVERSION 3)
set_property(TARGET ClimbingStats PROPERTY
  INTERFACE_ClimbingStats_MAJOR_VERSION 3)
set_property(TARGET ClimbingStats APPEND PROPERTY
  COMPATIBLE_INTERFACE_STRING ClimbingStats_MAJOR_VERSION
)

install(TARGETS ClimbingStats EXPORT ClimbingStatsTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)
install(
  FILES
    climbingstats.h
    "${CMAKE_CURRENT_BINARY_DIR}/climbingstats_export.h"
  DESTINATION
    include
  COMPONENT
    Devel
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/ClimbingStats/ClimbingStatsConfigVersion.cmake"
  VERSION ${Codefeeling_VERSION}
  COMPATIBILITY AnyNewerVersion
)

export(EXPORT ClimbingStatsTargets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/ClimbingStats/ClimbingStatsTargets.cmake"
  NAMESPACE Codefeeling::
)
configure_file(cmake/ClimbingStatsConfig.cmake
  "${CMAKE_CURRENT_BINARY_DIR}/ClimbingStats/ClimbingStatsConfig.cmake"
  COPYONLY
)

set(ConfigPackageLocation lib/cmake/ClimbingStats)
install(EXPORT ClimbingStatsTargets
  FILE
    ClimbingStatsTargets.cmake
  NAMESPACE
    Codefeeling::
  DESTINATION
    ${ConfigPackageLocation}
)
install(
  FILES
    cmake/ClimbingStatsConfig.cmake
    "${CMAKE_CURRENT_BINARY_DIR}/ClimbingStats/ClimbingStatsConfigVersion.cmake"
  DESTINATION
    ${ConfigPackageLocation}
  COMPONENT
    Devel
)