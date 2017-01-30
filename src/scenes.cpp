#include <iostream>
#include "scenes.hpp"
#include "player.hpp"

MainScene::MainScene() : Scene() {
}

MainScene::~MainScene() {
}

void MainScene::init() {
    this->entities.push_back(new Player());
    Scene::init();
}

void MainScene::update() {
}

void MainScene::render() {
}

