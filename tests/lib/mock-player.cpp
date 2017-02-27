#include "player/player.hpp"
#include "player/playerconfig.hpp"
#include "player/inputhandler.hpp"

bool initialized = false;
Player* player;
PlayerConfig* config;
InputMapping::InputHandler* mockInput;
AnimationBank* bank;

Player makeMockPlayer(Pair initialPosition) {
    if (!initialized) {
        initialized = true;
        config = new PlayerConfig("assets/attributes.yaml");
        bank = new AnimationBank();
        mockInput = new InputMapping::JoystickInputHandler();
    }

    return Player(config, mockInput, bank, initialPosition);
}