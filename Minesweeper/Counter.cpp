//
//  Counter.cpp
//  Minesweeper
//
//  Created by Fabio Suarez on 11/25/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#include <stdio.h>
#include "Counter.h"

Counter::Counter() {
    this->digits[0] = 0;
    this->digits[1] = 5;
    this->digits[2] = 0;
    setPosition(0, 32 * 16);
    setTexture("./images/digits.png");
    this->sprites[0] = Sprite(texture);
    this->sprites[1] = Sprite(texture);
    this->sprites[2] = Sprite(texture);
    this->sprites[0].setPosition(position);
    this->sprites[1].setPosition(position.x + 21, position.y);
    this->sprites[2].setPosition(position.x + 42, position.y);
    this->sprites[0].setTextureRect(IntRect(0 + 21 * this->digits[0], 0, 21, 32));
    this->sprites[1].setTextureRect(IntRect(0 + 21 * this->digits[1], 0, 21, 32));
    this->sprites[2].setTextureRect(IntRect(0 + 21 * this->digits[2], 0, 21, 32));
}

void Counter::subtract() {
    if (this->digits[2] != 0 && this->digits[1] != 0 && this->digits[0] != 10) {
        this->digits[2]--;
    } else if (this->digits[2] == 0 && this->digits[1] != 0 && this->digits[0] != 10){
        this->digits[2] = 9;
        this->digits[1]--;
    } else if (this->digits[1] == 0 && this->digits[0] == 0 && this->digits[2] != 0) {
        this->digits[2]--;
    } else if (this->digits[2] == 0 && this->digits[1] == 0 && this->digits[0] == 0) {
        this->digits[0] = 10;
        this->digits[1] = 0;
        this->digits[2]++;
    } else if (this->digits[0] == 10 && this->digits[2] != 9) {
        this->digits[2]++;
    } else if (this->digits[0] == 10 && this->digits[2] == 9) {
        this->digits[2] = 0;
        this->digits[1]++;
    } else if (this->digits[0] == 10 && this->digits[2] == 0 && this->digits[1] > 0) {
        this->digits[2]++;
    }
    this->sprites[0].setTextureRect(IntRect(0 + 21 * this->digits[0], 0, 21, 32));
    this->sprites[1].setTextureRect(IntRect(0 + 21 * this->digits[1], 0, 21, 32));
    this->sprites[2].setTextureRect(IntRect(0 + 21 * this->digits[2], 0, 21, 32));
}

Counter::Counter(unsigned int count) {
    auto first = count / 10 % 10;
    auto second = count % 10;
    this->digits[0] = 0;
    this->digits[1] = first;
    this->digits[2] = second;
    setPosition(0, 32 * 16);
    setTexture("./images/digits.png");
    this->sprites[0] = Sprite(texture);
    this->sprites[1] = Sprite(texture);
    this->sprites[2] = Sprite(texture);
    this->sprites[0].setPosition(position);
    this->sprites[1].setPosition(position.x + 21, position.y);
    this->sprites[2].setPosition(position.x + 42, position.y);
    this->sprites[0].setTextureRect(IntRect(0 + 21 * this->digits[0], 0, 21, 32));
    this->sprites[1].setTextureRect(IntRect(0 + 21 * this->digits[1], 0, 21, 32));
    this->sprites[2].setTextureRect(IntRect(0 + 21 * this->digits[2], 0, 21, 32));
}

void Counter::add() {
    if (this->digits[2] != 9 && this->digits[0] != 10) {
        this->digits[2]++;
    } else if (this->digits[2] == 9 && this->digits[0] != 10){
        this->digits[2] = 0;
        this->digits[1]++;
    } else if (this->digits[2] <= 9 && this->digits[0] == 10 && this->digits[1] == 0) {
        this->digits[2]--;
        if (this->digits[2] == 0) {
            this->digits[0] = 0;
        }
    } else if (this->digits[2] == 0 && this->digits[0] == 10 && this->digits[1] > 0) {
        this->digits[2] = 9;
        this->digits[1]--;
    } else if (this->digits[2] != 9 && this->digits[0] == 10 && this->digits[1] > 0) {
        this->digits[2]--;
    }
    this->sprites[0].setTextureRect(IntRect(0 + 21 * this->digits[0], 0, 21, 32));
    this->sprites[1].setTextureRect(IntRect(0 + 21 * this->digits[1], 0, 21, 32));
    this->sprites[2].setTextureRect(IntRect(0 + 21 * this->digits[2], 0, 21, 32));
}

void Counter::reset() {
    this->digits[0] = 5;
    this->digits[1] = 0;
    this->sprites[0].setTextureRect(IntRect(0 + 21 * this->digits[0], 0, 21, 32));
    this->sprites[1].setTextureRect(IntRect(0 + 21 * this->digits[1], 0, 21, 32));
}
