cmake_minimum_required(VERSION 3.28)
project(tictactoe LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_definitions(-DASSETS_DIR="${ASSETS_DIR}")

add_executable(main src/main.cpp
        src/objects/board.cpp
        src/objects/board.hpp
        src/scenes/scene.cpp
        src/scenes/scene.hpp
        src/scenes/menu.cpp
        src/scenes/menu.hpp
        src/objects/button.cpp
        src/objects/button.hpp
        src/utils/texture_manager.cpp
        src/utils/texture_manager.hpp
        src/utils/sound_manager.cpp
        src/utils/sound_manager.hpp)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)
