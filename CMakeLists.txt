cmake_minimum_required(VERSION 3.29)

# Project Name
set(PROJECT_NAME EnTT)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

# FetchContent
include(FetchContent)

# Raylib
FetchContent_Declare(
        raylib_external
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
)
FetchContent_MakeAvailable(raylib_external)

#Project Files
add_executable(${PROJECT_NAME} main.cpp
        include/WindowProperties.h
        include/SceneManager.h
        include/Scene.h
        include/Scenes/PlayingScene.h
        include/Scenes/MainMenuScene.h
        src/SceneManager.cpp
        src/Scene.cpp
        src/Scenes/PlayingScene.cpp
        src/Scenes/MainMenuScene.cpp
        include/SnakeGame.h
        src/SnakeGame.cpp
        include/Components/Engine/Transform.h
        include/Components/Engine/SpriteRenderer.h
        include/SnakeEntity.h
        src/SnakeEntity.cpp
        include/Components/Engine/PlayerInput.h
        include/Components/CustomComponent/PlayerMovement.h
        include/Entity.h
        include/Components/Engine/BoxCollider.h
        include/Apple.h
        src/Apple.cpp
        include/Components/Engine/Component.h
        src/Entity.cpp
        include/Components/CustomComponent/CustomComponent.h
        include/Components/Engine/ScriptableComponent.h
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        raylib
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

# Include Vendor Libraries
target_include_directories(${PROJECT_NAME} PRIVATE vendor/entt/include)