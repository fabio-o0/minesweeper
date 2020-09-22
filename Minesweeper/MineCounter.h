//
//  MineCounter.h
//  Minesweeper
//
//  Created by Fabio Suarez on 11/26/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#pragma once
#include "GameObject.h"

class MineCounter : public GameObject {
private:
    
public:
    int count;
    Texture textures[8];
    Sprite sprites[8];
    MineCounter();
    MineCounter(float x, float y);
    MineCounter(int count, float x, float y);
    void setCount(int count);
};
