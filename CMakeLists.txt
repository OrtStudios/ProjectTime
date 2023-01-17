cmake_minimum_required(VERSION 3.0.0)
project(Core VERSION 0.1.0)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Dist")
set(CMAKE_BUILD_TYPE "Release") #? Change this to "Debug" or "Dist" for different configurations

set (CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()

add_library(Core Core/Core.h)
include_directories(Core/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_custom_command(TARGET Core POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Core> ${CMAKE_SOURCE_DIR}/assets/Core.dll)