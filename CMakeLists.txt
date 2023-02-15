
cmake_minimum_required(VERSION 3.13)

project(ProjectTime)

add_library(Core SHARED
    Core/Core.cpp
    Core/Core.h
)

target_include_directories(Core
    PRIVATE
        Core/include
        Core/src
        Core
)

file(GLOB_RECURSE CPP_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/Core/src/*.cpp")
file(GLOB_RECURSE H_SOURCE_FILES   "${CMAKE_CURRENT_SOURCE_DIR}/Core/src/*.h")
target_sources(Core PRIVATE ${CPP_SOURCE_FILES})
target_sources(Core PRIVATE ${H_SOURCE_FILES})

target_compile_features(Core PRIVATE cxx_std_20)

add_custom_command(TARGET Core POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Core> ${CMAKE_SOURCE_DIR}/assets
)