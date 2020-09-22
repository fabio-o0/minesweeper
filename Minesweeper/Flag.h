//
//  Flag.h
//  Minesweeper
//
//  Created by Fabio Suarez on 11/25/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#pragma once

#include "GameObject.h"
#include "States.h"

class Flag : public GameObject {
private:
    
public:
    State state;
    void setState(State state);
    Flag();
    Flag(Vector2f position);
    Flag(float x, float y);
};
