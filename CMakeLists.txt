cmake_minimum_required(VERSION 3.29)

set(ENGINE_PROJECT_NAME Engine)
set(GAME_PROJECT_NAME Game)

# Project Name
project(${GAME_PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

# FetchContent
include(FetchContent)

# Raylib
FetchContent_Declare(
        raylib_external
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
)
FetchContent_MakeAvailable(raylib_external)

# Engine Library
add_library(${ENGINE_PROJECT_NAME} STATIC
        engine/include/WindowProperties.h
        engine/include/Engine.h
        engine/include/SceneManager.h
        engine/include/Scene.h
        engine/include/Entity.h
        engine/include/Components/Engine/BoxCollider.h
        engine/include/Components/Engine/Transform.h
        engine/include/Components/Engine/SpriteRenderer.h

        engine/src/Engine.cpp
        engine/src/SceneManager.cpp
        engine/src/Scene.cpp
        engine/src/Entity.cpp
        engine/include/Vector2.h
        engine/src/Components/Engine/BoxCollider.cpp
        engine/src/Components/Engine/SpriteRenderer.cpp
)

# Include Raylib in Engine
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE raylib)

# Engine include directories
target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC engine/include engine/vendor/entt/include)

# Game Executable
add_executable(${GAME_PROJECT_NAME} game/main.cpp
        game/include/SnakeGame.h

        game/src/SnakeGame.cpp
        game/include/Scenes/MainMenuScene.h
        game/src/Scenes/MainMenuScene.cpp
        game/src/Scenes/PlayingScene.cpp
        game/src/Apple.cpp
        game/src/SnakeEntity.cpp
)

# Import raylib to Game - Needed for Textures
target_link_libraries(${GAME_PROJECT_NAME} PRIVATE raylib)

# Import Engine to Game
target_link_libraries(${GAME_PROJECT_NAME} PRIVATE ${ENGINE_PROJECT_NAME})
target_include_directories(${GAME_PROJECT_NAME} PRIVATE engine/include game/include)