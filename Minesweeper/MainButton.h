//
//  MainButton.h
//  Minesweeper
//
//  Created by Fabio Suarez on 11/25/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#pragma once

#include "Button.h"
#include "States.h"

class MainButton : public Button {
private:
    
public:
    Kind kind;
    MainButton();
    MainButton(Vector2f position, Kind kind);
    MainButton(float x, float y, Kind kind);
    void setKind(Kind kind);
};
