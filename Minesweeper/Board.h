//
//  Board.h
//  Minesweeper
//
//  Created by Fabio Suarez on 11/24/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#pragma once
#include <fstream>
#include "Tile.h"
#include "Mine.h"
#include "MainButton.h"
#include "Flag.h"
#include "Counter.h"

class Board {
private:
public:
    unsigned int mineCount;
    bool wasInDebug;
    State desiredState;
    MainButton* mainButton;
    Counter* counter;
    Tile* tileGrid[25][16];
    Button* buttons[4];
    Mine* mineGrid[25][16];
    Board();
    Board(unsigned int i);
    void loadMines(unsigned int i);
    ~Board();
    void setMines();
    bool hasWon();
    void setDebug();
};
