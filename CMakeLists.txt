cmake_minimum_required(VERSION 4.2.1)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

project(GameplayProject VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
set(SFML_LIB_NAME SFML)

FetchContent_Declare(
    ${SFML_LIB_NAME}
    GIT_REPOSITORY https://github.com/SFML/SFML
    GIT_TAG 3.0.0
    GIT_SHALLOW FALSE
)

FetchContent_MakeAvailable(${SFML_LIB_NAME})

set(GAMEPLAY_ENGINE_NAME GameplayEngine)
set(GAMEPLAY_GAME_NAME GameplayGame)

add_subdirectory(${GAMEPLAY_ENGINE_NAME})
add_subdirectory(${GAMEPLAY_GAME_NAME})