#include "player/inputhandler.hpp"
#include "player/player.hpp"
#include "player/playerconfig.hpp"

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
        mockInput = new InputMapping::JoystickInputHandler(
            InputMapping::gamecubeButtons, InputMapping::gamecubeAxies, NULL);
    }

    return Player(config, mockInput, bank, initialPosition);
}
