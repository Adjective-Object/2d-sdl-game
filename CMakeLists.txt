cmake_minimum_required (VERSION 3.4)
include(cmake/common.cmake)

project (sdl_game)
set (sdl_game_VERSION_MAJOR 0)
set (sdl_game_VERSION_MINOR 0)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_CXX_FLAGS "-fPIC -g -Wall -std=c++11")

########################
# external dependencies #
#########################

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)
PKG_SEARCH_MODULE(SDL2GFX REQUIRED SDL2_gfx)
PKG_SEARCH_MODULE(YAML_CPP REQUIRED yaml-cpp)
PKG_SEARCH_MODULE(GLM REQUIRED glm)
PKG_SEARCH_MODULE(ASSIMP REQUIRED assimp)
PKG_SEARCH_MODULE(PCI REQUIRED pciaccess)

# normalize vars between pkg-search and local lookup for osx
if (NOT APPLE)
PKG_SEARCH_MODULE(OPENGL REQUIRED gl)
else()
    find_package(OpenGL REQUIRED)
    SET(OPENGL_INCLUDE_DIRS ${OPENGL_INCLUDE_DIR})
endif()
include(cmake/gtest.cmake)

##########################
# project source objects #
##########################
SET(ALL_INCLUDE_DIRS
    ${SDL2_INCLUDE_DIRS}
    ${SDL2IMAGE_INCLUDE_DIRS}
    ${SDL2TTF_INCLUDE_DIRS}
    ${SDL2GFX_INCLUDE_DIRS}
    ${YAML_CPP_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIRS}
    ${ASSIMP_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIRS}
    ${PCI_INCLUDE_DIRS}
    "src")

foreach(dir ${ALL_INCLUDE_DIRS})
MESSAGE(STATUS "INCLUDE: " ${dir})
endforeach()

SET(ALL_LIBRARIES
    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
    ${SDL2TTF_LIBRARIES}
    ${SDL2GFX_LIBRARIES}
    ${YAML_CPP_LIBRARIES}
    ${ASSIMP_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${PCI_LIBRARIES}
    )

foreach(dir ${ALL_LIBRARIES})
MESSAGE(STATUS "LIB: " ${dir})
endforeach()

set(LIB_SRCS
    src/scenes/mainscene.hpp
    src/iterator_wrapper.hpp
    src/scenes/mainscene.cpp
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
    src/player/ecbmesh.hpp
    src/player/ecbmesh.cpp
    src/player/playercollision.hpp
    src/player/playercollision.cpp
    src/player/inputhandler.hpp
    src/player/inputhandler.cpp
    src/terrain/platform_point_iterator.hpp
    src/terrain/platform_point_iterator.cpp
    src/terrain/platform_segment_iterator.hpp
    src/terrain/platform_segment_iterator.cpp
    src/terrain/platform.hpp
    src/terrain/platform.cpp
    src/terrain/platformsegment.hpp
    src/terrain/platformsegment.cpp
    src/terrain/platformpoint.hpp
    src/terrain/platformpoint.cpp
    src/terrain/map.hpp
    src/terrain/map.cpp
    src/terrain/map_movement.hpp
    src/terrain/map_movement.cpp
    src/terrain/ledge.hpp
    src/terrain/ledge.cpp
    src/engine/util.hpp
    src/engine/util.cpp
    src/engine/game.hpp
    src/engine/game.cpp
    src/engine/input/input.hpp
    src/engine/input/input.cpp
    src/engine/input/joystick.hpp
    src/engine/input/joystick.cpp
    src/engine/input/keyboard.hpp
    src/engine/input/keyboard.cpp
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
    src/engine/scene.cpp
    src/engine/renderer/abstractrenderer.hpp
    src/engine/renderer/meshrenderer.hpp
    src/engine/renderer/meshrenderer.cpp
    src/engine/renderer/multirenderer.hpp
    src/engine/renderer/multimeshrenderer.cpp
    src/engine/renderer/multimeshrenderer.hpp
    src/engine/renderer/screenrenderer.cpp
    src/engine/renderer/screenrenderer.hpp
    src/engine/material/material.hpp
    src/engine/material/material.cpp
    src/engine/gl.h
    src/engine/mesh/cube.cpp
    src/engine/mesh/cube.hpp
    src/engine/mesh/worldspacemesh.hpp
    src/engine/mesh/worldspacemesh.cpp
    src/engine/model/loader/modelloader.cpp
    src/engine/model/loader/modelloader.hpp
    src/engine/model/model.cpp
    src/engine/model/model.hpp
    src/engine/shader/lib/loadshaders.hpp
    src/engine/shader/lib/loadshaders.cpp
    src/engine/shader/primitiveshader.cpp
    src/engine/shader/primitiveshader.hpp
    src/engine/shader/meshshader.cpp
    src/engine/shader/meshshader.hpp
    src/engine/shader/screenspaceshader.cpp
    src/engine/shader/screenspaceshader.hpp
    src/engine/mesh/screenspacequad.cpp
    src/engine/mesh/screenspacequad.hpp
    src/engine/meshanim/meshanim.cpp
    src/engine/model/loader/boneweightloader.hpp
    src/engine/model/loader/boneweightloader.cpp
    src/engine/model/loader/loadedmesh.hpp
        src/engine/model/modelmesh.hpp
    src/engine/model/loader/AnimationLoader.cpp
    src/engine/model/loader/AnimationLoader.hpp
    src/engine/shader/skinnedmeshshader.cpp
    src/engine/shader/skinnedmeshshader.hpp)
add_library(SDL_GAME_LIB OBJECT ${LIB_SRCS})
target_include_directories(SDL_GAME_LIB PUBLIC
    ${ALL_INCLUDE_DIRS}
)

set(TEST_SRCS
    tests/platform.cpp
    tests/player.cpp
    tests/ecb.cpp
    tests/map.cpp
    tests/util.cpp
        tests/boneweightloader.cpp
    tests/lib/mock-player.cpp
    tests/lib/mock-player.hpp tests/animationloader.cpp tests/meshshader.cpp)
add_library(TEST_LIB OBJECT ${TEST_SRCS})
target_include_directories(TEST_LIB PUBLIC
    ${ALL_INCLUDE_DIRS}
    ${GTEST_INCLUDE_DIR}
    "tests"
)

set(ALL_SRCS ${LIB_SRCS} ${TEST_SRCS} src/main.cpp tests/main.cpp)
PREPEND(ABSOLUTE_ALL_SRCS ${PROJECT_SOURCE_DIR} ${ALL_SRCS})

#####################
# output executable #
#####################
MESSAGE(STATUS "GTEST: " ${GTEST_INCLUDE_DIR})
add_executable(ctest
    tests/main.cpp
    $<TARGET_OBJECTS:TEST_LIB>
    $<TARGET_OBJECTS:SDL_GAME_LIB>)
target_link_libraries(ctest
    ${ALL_LIBRARIES}
    ${GTEST_LIBRARY}
    ${GTEST_LIBRARY_MAIN}
    ${TEST_LIB}
    ${SDL_GAME_LIB}
    )
target_include_directories(ctest PUBLIC
    ${ALL_INCLUDE_DIRS}
    ${GTEST_INCLUDE_DIR}
    ${ASSIMP_INCLUDE_DIRS}
    "src"
    )

add_executable(sdl_game
    src/main.cpp
    $<TARGET_OBJECTS:SDL_GAME_LIB>)
target_link_libraries(sdl_game
    ${ALL_LIBRARIES}
    ${SDL_GAME_LIB}
    ${PCI_LIBRARIES}
    )
target_include_directories(sdl_game PUBLIC
    ${ALL_INCLUDE_DIRS}
    "src"
    )

copy_files(sdl_game ${PROJECT_SOURCE_DIR}/assets/* ${CMAKE_BINARY_DIR}/assets)
copy_files(ctest ${PROJECT_SOURCE_DIR}/test-assets/* ${CMAKE_BINARY_DIR}/test-assets)

########################################
# Code formatting and linting commands #
########################################
add_custom_target(lint
    COMMAND cppcheck
        --std=c11
        --enable=warning
        --enable=missingInclude
        --enable=performance
        src/sdl_game.cpp ${ABSOLUTE_ALL_SRCS})

add_custom_target(format
    COMMAND clang-format -i ${ABSOLUTE_ALL_SRCS})

add_custom_target(run_tests
    COMMAND ./ctest
    DEPENDS ctest)

add_custom_target(run_tests_valgrind
    COMMAND valgrind ./ctest
    DEPENDS ctest)

