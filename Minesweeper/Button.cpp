//
//  Button.cpp
//  Minesweeper
//
//  Created by Fabio Suarez on 11/24/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#include <stdio.h>
#include "Button.h"

Button::Button() {
    setPosition(12 * 32, 16 * 32);
    setTexture("./images/face_happy.png");
    setSprite();
}

Button::Button(Vector2f position, int type) {
    this->position = position;
    if (type == 0) {
        setTexture("./images/debug.png");
    } else if (type == 1) {
        setTexture("./images/test_1.png");
    }
    else if (type == 2) {
        setTexture("./images/test_2.png");
    }
    else if (type == 3) {
        setTexture("./images/test_3.png");
    }
    setSprite();
}

Button::Button(float x, float y, int type) {
    setPosition(x, y);
    if (type == 0) {
        setTexture("./images/debug.png");
    } else if (type == 1) {
        setTexture("./images/test_1.png");
    }
    else if (type == 2) {
        setTexture("./images/test_2.png");
    }
    else if (type == 3) {
        setTexture("./images/test_3.png");
    }
    setSprite();
}
