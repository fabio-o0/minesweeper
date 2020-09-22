//
//  Tile.h
//  Minesweeper
//
//  Created by Fabio Suarez on 11/24/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#pragma once

#include "States.h"
#include "GameObject.h"
#include "MineCounter.h"
#include "Flag.h"

class Tile : public GameObject {
private:
    
public:
    std::vector<Tile*> adjacentTiles;
    MineCounter* counter;
    bool hasMine;
    State state;
    Flag* flag;
    Tile();
    ~Tile();
    Tile(State state, Vector2f position, bool hasMine);
    Tile(State state, float x, float y, bool hasMine);
    void setTexture(State state);
    void setState(State state);
    void setHasMine(bool hasMine);
    void uncoverAdjacent();
    void setCounter(int count);
};
