//
//  Mine.cpp
//  Minesweeper
//
//  Created by Fabio Suarez on 11/24/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#include <stdio.h>
#include "Mine.h"

Mine::Mine() {
    setPosition(0,0);
    setTexture("./images/mine.png");
    setSprite();
}

Mine::Mine(Vector2f position) {
    setPosition(position);
    
}

Mine::Mine(float x, float y) {
    setPosition(x, y);
    setTexture("./images/mine.png");
    setSprite();
}
