#include "keyboard.hpp"
#include <stdint.h>
#include <iostream>
#include <vector>

Keyboard::Keyboard(size_t historySize) : historySize(historySize) {
    heldKeys = new std::set<int>[historySize];
    downKeys = new std::set<int>[historySize];
    upKeys = new std::set<int>[historySize];
    for (size_t i = 0; i < historySize; i++) {
        heldKeys[i] = std::set<int>();
        downKeys[i] = std::set<int>();
        upKeys[i] = std::set<int>();
    }
}

void Keyboard::clear() {
    size_t old_current_history = currentHistory;
    currentHistory = ((currentHistory + 1) % historySize);
    downKeys[currentHistory].clear();
    upKeys[currentHistory].clear();
    heldKeys[currentHistory].clear();
    for (int key : heldKeys[old_current_history]) {
        heldKeys[currentHistory].insert(key);
    }
}

void Keyboard::setDown(unsigned int keyId) {
    downKeys[currentHistory].insert(keyId);
    heldKeys[currentHistory].insert(keyId);
}

void Keyboard::setUp(unsigned int keyId) {
    heldKeys[currentHistory].erase(keyId);
    upKeys[currentHistory].insert(keyId);
}

template <class T>
bool contains(const std::set<T>& container, const T elem) {
    return container.find(elem) != container.end();
}

bool Keyboard::up(int keysym, int framesBack) {
    size_t frame = (currentHistory + historySize) % historySize;
    return contains<int>(upKeys[frame], keysym);
}

bool Keyboard::down(int keysym, int framesBack) {
    size_t frame = (currentHistory + historySize) % historySize;
    return contains<int>(downKeys[frame], keysym);
}

bool Keyboard::held(int keysym, int framesBack) {
    size_t frame = (currentHistory + historySize) % historySize;
    return contains<int>(heldKeys[frame], keysym);
}
