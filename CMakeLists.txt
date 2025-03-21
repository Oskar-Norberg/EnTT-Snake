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
add_executable(${PROJECT_NAME} main.cpp)



target_link_libraries(${PROJECT_NAME}
        PRIVATE
        raylib
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

# Include Vendor Libraries
target_include_directories(${PROJECT_NAME} PRIVATE vendor/entt/include)