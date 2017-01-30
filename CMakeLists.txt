cmake_minimum_required (VERSION 3.4)
include(ExternalProject)

project (sdl_game)
set (sdl_game_VERSION_MAJOR 0)
set (sdl_game_VERSION_MINOR 0)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_CXX_FLAGS "-fPIC -g -Wall -std=c++11")

#########################
# external dependencies #
#########################

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

ExternalProject_Add(
    yaml-cpp
    # no download since it's in a git submodule
    DOWNLOAD_COMMAND ""
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/yaml-cpp
    CONFIGURE_COMMAND cmake CmakeLists.txt
    BUILD_COMMAND make
    BUILD_IN_SOURCE 1
    INSTALL_COMMAND ""
)


##########################
# project source objects #
##########################
set(LIB_SRCS 
    src/scenes.hpp
    src/scenes.cpp
    src/player.hpp
    src/player.cpp
    src/engine/util.hpp
    src/engine/util.cpp
    src/engine/game.hpp
    src/engine/game.cpp
    src/engine/input.hpp
    src/engine/input.cpp
    src/engine/entity.hpp
    src/engine/entity.cpp
    src/engine/sprite.hpp
    src/engine/sprite.cpp
    src/engine/pair.hpp
    src/engine/pair.cpp
    src/engine/scene.hpp
    src/engine/scene.cpp)
add_library(SDL_GAME_LIB OBJECT ${LIB_SRCS})
target_include_directories(
    SDL_GAME_LIB PUBLIC
    ${SDL2_INCLUDE_DIRS}
    ${SDL2IMAGE_INCLUDE_DIRS}
    ./yaml-cpp
)

set(ALL_SRCS ${LIB_SRCS} src/main.cpp)

#####################
# output executable #
#####################
add_executable(sdl_game
    src/main.cpp
    $<TARGET_OBJECTS:SDL_GAME_LIB>)
target_link_libraries(sdl_game ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
target_include_directories(sdl_game PUBLIC
    ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})


########################################
# Code formatting and linting commands #
########################################
add_custom_target(lint
    COMMAND cppcheck 
        --std=c11
        --enable=warning
        --enable=missingInclude
        --enable=performance
        src/sdl_game.cpp ${ALL_SRCS})

add_custom_target(format
    COMMAND clang-format -i ${ALL_SRCS})


