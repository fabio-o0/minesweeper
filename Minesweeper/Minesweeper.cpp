//
//  Minesweeper.cpp
//  Minesweeper
//
//  Created by Fabio Suarez on 11/25/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Minesweeper.h"

Minesweeper::Minesweeper() {
    this->width = 800;
    this->height = 600;
    this->window = new MyRenderWindow(sf::VideoMode(width, height), "Minesweeper", sf::Style::Close | sf::Style::Titlebar);
    this->board = new Board;
}

void Minesweeper::start() {
    
    unsigned int prev = 0;
    unsigned int curr = 1;
    
    while(window->isOpen()) {
        Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                curr++;
                window->close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                curr++;
                window->close();
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                auto mousePos = sf::Mouse::getPosition(*window);
                
                //new game
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (mousePos.x > board->mainButton->position.x && mousePos.x < board->mainButton->position.x + 64) {
                        if (mousePos.y > board->mainButton->position.y && mousePos.y < board->mainButton->position.y + 64) {
                            curr++;
                            delete board;
                            board = new Board();
                        }
                    }
                }
                
                for (unsigned int i = 0; i < 4; i++) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (mousePos.x > board->buttons[i]->position.x && mousePos.x < board->buttons[i]->position.x + 64) {
                            if (mousePos.y > board->buttons[i]->position.y && mousePos.y < board->buttons[i]->position.y + 64) {
                                if (i == 0) {
                                    board->setDebug();
                                } else {
                                    delete board;
                                    board = new Board(i);
                                }
                                curr++;
                            }
                        }
                    }
                }
                
                if (board->mainButton->kind == happy) {
                    //tap a tile
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        for (unsigned int i = 0; i < 25; i++) {
                            for (unsigned int j = 0; j < 16; j++) {
                                if (mousePos.x > i * 32 && mousePos.x < i * 32 + 32) {
                                    if (mousePos.y > j * 32 && mousePos.y < j * 32 + 32) {
                                        if (board->tileGrid[i][j]->flag->state != revealed) {
                                            if (board->tileGrid[i][j]->hasMine) {
                                                for (unsigned int k = 0; k < 25; k++) {
                                                    for (unsigned int h = 0; h < 16; h++) {
                                                        if (board->tileGrid[k][h]->hasMine) {
                                                            if (board->tileGrid[k][h]->flag->state == revealed) {
                                                                curr++;
                                                                board->tileGrid[k][h]->flag->setState(hidden);
                                                            }
                                                            curr++;
                                                            board->tileGrid[k][h]->setState(revealed);
                                                        }
                                                    }
                                                }
                                                curr++;
                                                board->counter->subtract();
                                                board->mainButton->setKind(lose);
                                            }
                                            curr++;
                                            board->tileGrid[i][j]->setState(revealed);
                                            if (board->tileGrid[i][j]->hasMine == false) {
                                                curr++;
                                                board->tileGrid[i][j]->uncoverAdjacent();
                                            }
                                            if (board->tileGrid[i][j]->flag->state == revealed) {
                                                curr++;
                                                board->tileGrid[i][j]->flag->setState(hidden);
                                                board->counter->add();
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                            
                    //flag a tile
                    if (event.mouseButton.button == sf::Mouse::Right) {
                        for (unsigned int i = 0; i < 25; i++) {
                            for (unsigned int j = 0; j < 16; j++) {
                                if (mousePos.x > i * 32 && mousePos.x < i * 32 + 32) {
                                    if (mousePos.y > j * 32 && mousePos.y < j * 32 + 32) {
                                        if (board->tileGrid[i][j]->state == hidden) {
                                            if (board->tileGrid[i][j]->flag->state == revealed) {
                                                board->tileGrid[i][j]->flag->setState(hidden);
                                                board->counter->add();
                                            } else {
                                                board->tileGrid[i][j]->flag->setState(revealed);
                                                board->counter->subtract();
                                            }
                                            curr++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    
                    if (board->hasWon()) {
                        curr++;
                        board->mainButton->setKind(win);
                    }
                }
            }
        }
        
        if (curr != prev) {
            prev = curr;
            std::cout << "updated" << std::endl;
            window->clear();
            window->draw(*board);
            window->display();
        }
    }
}
