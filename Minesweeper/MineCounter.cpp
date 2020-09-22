//
//  MineCounter.cpp
//  Minesweeper
//
//  Created by Fabio Suarez on 11/26/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#include <stdio.h>
#include "MineCounter.h"

MineCounter::MineCounter() {
    setPosition(0,0);
    this->count = 0;
    for (unsigned int i = 0; i < 8; i++) {
        try {
            this->textures[i].loadFromFile("./images/number_" + std::to_string(i + 1) + ".png");
        } catch (std::exception e) {}
        this->sprites[i] = Sprite(this->textures[i]);
        this->sprites[i].setPosition(position.x, position.y);
    }
}

MineCounter::MineCounter(float x, float y) {
    setPosition(x,y);
    this->count = 0;
    for (unsigned int i = 0; i < 8; i++) {
        try {
            this->textures[i].loadFromFile("./images/number_" + std::to_string(i + 1) + ".png");
        } catch (std::exception e) {}
        this->sprites[i] = Sprite(this->textures[i]);
        this->sprites[i].setPosition(position.x, position.y);
    }
}

MineCounter::MineCounter(int count, float x, float y) {
    setPosition(x,y);
    this->count = count;
    for (unsigned int i = 0; i < 8; i++) {
        try {
            this->textures[i].loadFromFile("./images/number_" + std::to_string(i + 1) + ".png");
        } catch (std::exception e) {}
        this->sprites[i] = Sprite(this->textures[i]);
        this->sprites[i].setPosition(position.x, position.y);
    }
}

void MineCounter::setCount(int count) {
    this->count = count;
}
