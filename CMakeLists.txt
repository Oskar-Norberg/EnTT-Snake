cmake_minimum_required(VERSION 3.29)

# Project Name
set(ENGINE_PROJECT_NAME Engine)

project(${ENGINE_PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

# FetchContent
include(FetchContent)

# Raylib
FetchContent_Declare(
        raylib_external
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
)
FetchContent_MakeAvailable(raylib_external)

# Define the Engine library
add_library(${ENGINE_PROJECT_NAME} STATIC
        engine/include/WindowProperties.h
        engine/include/Engine.h
        engine/include/SceneManager.h
        engine/include/Scene.h
        engine/include/Entity.h
        
        engine/src/Engine.cpp
        engine/src/SceneManager.cpp
        engine/src/Scene.cpp
        engine/src/Entity.cpp
)

# Link libraries
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE raylib)

# Include directories
target_include_directories(${ENGINE_PROJECT_NAME} PRIVATE engine/include)
target_include_directories(${ENGINE_PROJECT_NAME} PRIVATE include engine/vendor/entt/include)