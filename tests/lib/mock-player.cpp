#include "player/inputhandler.hpp"
#include "player/player.hpp"
#include "player/playerconfig.hpp"

bool initialized = false;
Player* player;
PlayerConfig* config;
InputMapping::InputHandler* mockInput;

Player makeMockPlayer(Pair initialPosition) {
    if (!initialized) {
        initialized = true;
        config = new PlayerConfig("assets/attributes.yaml");
        mockInput = new InputMapping::JoystickInputHandler(
            InputMapping::gamecubeButtons, InputMapping::gamecubeAxies, NULL);
    }

    return Player(config, mockInput, initialPosition);
}
