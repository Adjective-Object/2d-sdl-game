#include <iostream>
#include <SDL.h>

#include "engine/game.hpp"
#include "engine/scene.hpp"
#include "engine/util.hpp"
#include "scenes.hpp"

#define WINDOW_NAME "poop"

/*
 * Lesson 0: Test to make sure SDL is setup properly
 */
int main(int argc, char** argv){
    MainScene m = MainScene();
    Game g = Game(640, 480, m);

    std::cout << "entering main loop" << std::endl;
    g.start();
    std::cout << "exiting main loop" << std::endl;
   
    // quit everything
    std::cout << "shutting down" << std::endl;
    return 0;
}

