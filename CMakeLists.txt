cmake_minimum_required (VERSION 3.4)

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
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)
PKG_SEARCH_MODULE(YAML_CPP REQUIRED yaml-cpp)
set(GTEST_DIR $ENV{GTEST_DIR})
find_library(GTEST_LIBRARY 
                NAMES gtest 
                      libgtest 
                      libgtest.a 
                PATHS "${GTEST_DIR}/lib")
find_library(GTEST_LIBRARY_MAIN 
                NAMES gtest_main 
                      libgtest_main 
                      libgtest.a 
                PATHS "${GTEST_DIR}/lib")
set(GTEST_INCLUDE_DIR "${GTEST_DIR}/include")

##########################
# project source objects #
##########################
set(LIB_SRCS 
    src/scenes.hpp
    src/scenes.cpp
    src/util.hpp
    src/util.cpp
    src/player/player.hpp
    src/player/player.cpp
    src/player/action.hpp
    src/player/action.cpp
    src/player/playerconfig.hpp
    src/player/playerconfig.cpp
    src/player/animationbank.hpp
    src/player/animationbank.cpp
    src/player/ecb.hpp
    src/player/ecb.cpp
    src/player/playercollision.hpp
    src/player/playercollision.cpp
    src/terrain/platform.hpp
    src/terrain/platform.cpp
    src/engine/util.hpp
    src/engine/util.cpp
    src/engine/game.hpp
    src/engine/game.cpp
    src/engine/input.hpp
    src/engine/input.cpp
    src/engine/text.hpp
    src/engine/text.cpp
    src/engine/joystickindicator.hpp
    src/engine/joystickindicator.cpp
    src/engine/entity.hpp
    src/engine/entity.cpp
    src/engine/sprite.hpp
    src/engine/sprite.cpp
    src/engine/pair.hpp
    src/engine/pair.cpp
    src/engine/scene.hpp
    src/engine/scene.cpp)
add_library(SDL_GAME_LIB OBJECT ${LIB_SRCS})
target_include_directories(SDL_GAME_LIB PUBLIC
    ${SDL2_INCLUDE_DIRS}
    ${SDL2IMAGE_INCLUDE_DIRS}
    ${SDL2TTF_INCLUDE_DIRS}
    ${YAML_CPP_INCLUDE_DIRS}
    "src"
)

set(TEST_SRCS
    tests/platform.cpp
    tests/player.cpp
    tests/ecb.cpp
    tests/util.cpp)
add_library(TEST_LIB OBJECT ${TEST_SRCS})
target_include_directories(TEST_LIB PUBLIC
    ${SDL2_INCLUDE_DIRS}
    ${SDL2IMAGE_INCLUDE_DIRS}
    ${SDL2TTF_INCLUDE_DIRS}
    ${YAML_CPP_INCLUDE_DIRS}
    ${GTEST_INCLUDE_DIR}
    "src"
    )

set(ALL_SRCS ${LIB_SRCS} ${TEST_SRCS} src/main.cpp tests/main.cpp)

#####################
# output executable #
#####################
add_executable(ctest
    tests/main.cpp
    # $<TARGET_OBJECTS:TEST_LIB>
    $<TARGET_OBJECTS:SDL_GAME_LIB>)
target_link_libraries(ctest
    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES} 
    ${SDL2TTF_LIBRARIES} 
    ${YAML_CPP_LIBRARIES}
    ${GTEST_LIBRARY}
    ${GTEST_LIBRARY_MAIN}
    )
target_include_directories(ctest PUBLIC
    ${SDL2_INCLUDE_DIRS}
    ${SDL2IMAGE_INCLUDE_DIRS}
    ${SDL2TTF_INCLUDE_DIRS}
    ${YAML_CPP_INCLUDE_DIRS}
    ${GTEST_INCLUDE_DIR}
    "src"
    )

add_executable(sdl_game
    src/main.cpp
    $<TARGET_OBJECTS:SDL_GAME_LIB>)
target_link_libraries(sdl_game
    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES} 
    ${SDL2TTF_LIBRARIES} 
    ${YAML_CPP_LIBRARIES}
    )
target_include_directories(sdl_game PUBLIC
    ${SDL2_INCLUDE_DIRS}
    ${SDL2IMAGE_INCLUDE_DIRS}
    ${SDL2TTF_INCLUDE_DIRS}
    ${YAML_CPP_INCLUDE_DIRS}
    "src"
    )

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

add_custom_target(run_tests
    COMMAND ./ctest
    DEPENDS ctest)

add_custom_target(run_tests_valgrind
    COMMAND valgrind ./ctest
    DEPENDS ctest)

