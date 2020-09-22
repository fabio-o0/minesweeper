//
//  Button.h
//  Minesweeper
//
//  Created by Fabio Suarez on 11/24/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#pragma once

#include "GameObject.h"

class Button : public GameObject {
private:
public:
    Button();
    Button(Vector2f position, int type);
    Button(float x, float y, int type);
};
