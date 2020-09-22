//
//  MyRenderWindow.cpp
//  Minesweeper
//
//  Created by Fabio Suarez on 11/24/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#include <stdio.h>
#include "MyRenderWindow.h"

MyRenderWindow::MyRenderWindow(VideoMode mode, const String& title, Uint32 style, const ContextSettings& settings) : RenderWindow(mode, title, style, settings) {
}

void MyRenderWindow::draw(const Board& board) {
    for (unsigned int i = 0; i < 25; i++) {
        for (unsigned int j = 0; j < 16; j++) {
            if (board.desiredState == revealed || board.tileGrid[i][j]->state == revealed) {
               RenderWindow::draw(board.tileGrid[i][j]->sprite);
                if (board.mineGrid[i][j] != nullptr) {
                    RenderWindow::draw(board.mineGrid[i][j]->sprite);
                }
            } else {
                if (board.mineGrid[i][j] != nullptr) {
                    RenderWindow::draw(board.mineGrid[i][j]->sprite);
                }
                RenderWindow::draw(board.tileGrid[i][j]->sprite);
            }
            if (board.tileGrid[i][j]->flag->state == revealed) {
                RenderWindow::draw(board.tileGrid[i][j]->flag->sprite);
            }
            
            if (board.tileGrid[i][j]->state == revealed && board.tileGrid[i][j]->counter->count != 0 && board.tileGrid[i][j]->hasMine == false) {
                RenderWindow::draw(board.tileGrid[i][j]->counter->sprites[board.tileGrid[i][j]->counter->count - 1]);
            }
        }
    }
    for (unsigned int i = 0; i < 4; i++) {
        RenderWindow::draw(board.buttons[i]->sprite);
    }
    
    RenderWindow::draw(board.mainButton->sprite);
    
    for (unsigned int i = 0; i < 3; i++) {
        RenderWindow::draw(board.counter->sprites[i]);
    }
}
