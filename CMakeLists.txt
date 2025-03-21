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
        include/StateMachine.h
        include/State.h
        include/States/PlayingState.h
        include/States/MainMenuState.h
        src/StateMachine.cpp
        src/State.cpp
        src/States/PlayingState.cpp
        src/States/MainMenuState.cpp
        include/SnakeGame.h
        src/SnakeGame.cpp
        include/Components/Transform.h
        include/Components/SpriteRenderer.h
        include/SnakeEntity.h
        src/SnakeEntity.cpp
        include/Components/PlayerInput.h
        include/Components/PlayerMovement.h
        include/Entity.h
        include/BoxCollider.h
        include/Apple.h
        src/Apple.cpp
        include/Components/Collider.h
        include/Components/Updateable.h
        include/Components/Component.h
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        raylib
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

# Include Vendor Libraries
target_include_directories(${PROJECT_NAME} PRIVATE vendor/entt/include)