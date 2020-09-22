//
//  Counter.h
//  Minesweeper
//
//  Created by Fabio Suarez on 11/25/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#pragma once

#include "GameObject.h"

class Counter : public GameObject {
private:
public:
    unsigned int digits[3];
    Sprite sprites[3];
    Counter();
    Counter(unsigned int count);
    void subtract();
    void add();
    void reset();
};
