//
//  Mine.h
//  Minesweeper
//
//  Created by Fabio Suarez on 11/24/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#pragma once

#include "GameObject.h"

class Mine : public GameObject {
private:
public:
    Mine();
    Mine(Vector2f position);
    Mine(float x, float y);
};
