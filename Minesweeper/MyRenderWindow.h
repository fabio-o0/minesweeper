//
//  MyRenderWindow.h
//  Minesweeper
//
//  Created by Fabio Suarez on 11/24/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Board.h"

class MyRenderWindow : public RenderWindow {
public:
    MyRenderWindow(VideoMode mode, const String& title, Uint32 style = Style::Default, const ContextSettings& settings = ContextSettings());
    
    void draw(const Board& board);
};
