//
//  Minesweeper.h
//  Minesweeper
//
//  Created by Fabio Suarez on 11/25/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#pragma once

#include "MyRenderWindow.h"

class Minesweeper {
private:
public:
    float width;
    float height;
    MyRenderWindow* window;
    Board* board;
    Minesweeper();
    void start();
    void end();
};
