//
//  Flag.cpp
//  Minesweeper
//
//  Created by Fabio Suarez on 11/25/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#include <stdio.h>
#include "Flag.h"

Flag::Flag() {
    setPosition(0,0);
    setTexture("./images/flag.png");
    setSprite();
    setState(hidden);
}

Flag::Flag(Vector2f position) {
    setPosition(position);
    setTexture("./images/flag.png");
    setSprite();
    setState(hidden);
}

Flag::Flag(float x, float y) {
    setPosition(x,y);
    setTexture("./images/flag.png");
    setSprite();
    setState(hidden);
}

void Flag::setState(State state) {
    this->state = state;
}
