//
//  Board.cpp
//  Minesweeper
//
//  Created by Fabio Suarez on 11/24/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#include <stdio.h>
#include "Board.h"

Board::Board() {
    wasInDebug = false;
    desiredState = hidden;
    mineCount = 50;
    setMines();
    for (unsigned int i = 0; i < 25; i++) {
        for (unsigned int j = 0; j < 16; j++) {
            if (mineGrid[i][j] != nullptr) {
                tileGrid[i][j] = new Tile(hidden, i * 32, j * 32, true);
            } else {
                tileGrid[i][j] = new Tile(hidden, i * 32, j * 32, false);
            }
        }
    }
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            for (int h = -1; h <= 1; h++) {
                for (int k = -1; k <= 1; k++) {
                    if (i + h > - 1 && i + h < 25 && j + k > -1 && j + k < 16) {
                        if (h != 0 || k != 0) {
                            tileGrid[i][j]->adjacentTiles.push_back(tileGrid[i + h][j + k]);
                        }
                    }
                }
            }
        }
    }
    for (unsigned int i = 0; i < 4; i++) {
        buttons[i] = new Button(i * 64 + (32 * 25 - 64 * 4), 16 * 32, i);
    }
    mainButton = new MainButton();
    counter = new Counter(mineCount);
}

Board::Board(unsigned int i) {
    wasInDebug = false;
    desiredState = hidden;
    loadMines(i);
    for (unsigned int i = 0; i < 25; i++) {
        for (unsigned int j = 0; j < 16; j++) {
            if (mineGrid[i][j] != nullptr) {
                tileGrid[i][j] = new Tile(hidden, i * 32, j * 32, true);
            } else {
                tileGrid[i][j] = new Tile(hidden, i * 32, j * 32, false);
            }
        }
    }
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            for (int h = -1; h <= 1; h++) {
                for (int k = -1; k <= 1; k++) {
                    if (i + h > - 1 && i + h < 25 && j + k > -1 && j + k < 16) {
                        if (h != 0 || k != 0) {
                            tileGrid[i][j]->adjacentTiles.push_back(tileGrid[i + h][j + k]);
                        }
                    }
                }
            }
        }
    }
    for (unsigned int i = 0; i < 4; i++) {
        buttons[i] = new Button(i * 64 + (32 * 25 - 64 * 4), 16 * 32, i);
    }
    mainButton = new MainButton();
    counter = new Counter(mineCount);
}

void Board::setMines() {
    for (unsigned int i = 0; i < 25; i++) {
        for (unsigned int j = 0; j < 16; j++) {
            mineGrid[i][j] = nullptr;
        }
    }
    
    std::vector<std::vector<int>> options;
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            options.push_back({i, j});
        }
    }
    
    std::random_shuffle(options.begin(),options.end());
    
    for (unsigned int n = 0; n < mineCount; n++) {
        auto choice = options.back();
        options.pop_back();
        int i = choice[0], j = choice[1];
        mineGrid[i][j] = new Mine(i * 32, j * 32);
    }
}

Board::~Board() {
    for (unsigned int i = 0; i < 25; i++) {
        for (unsigned int j = 0; j < 16; j++) {
            delete tileGrid[i][j];
        }
    }
    for (unsigned int i = 0; i < 4; i++) {
        delete buttons[i];
    }
    delete mainButton;
    for (unsigned int i = 0; i < 25; i++) {
        for (unsigned int j = 0; j < 16; j++) {
            delete mineGrid[i][j];
        }
    }
    delete counter;
}

bool Board::hasWon() {
    unsigned int tileCount = 0;
    for (unsigned int i = 0; i < 25; i++) {
        for (unsigned int j = 0; j < 16; j++) {
            if (tileGrid[i][j]->hasMine == false && tileGrid[i][j]->state == revealed) {
                tileCount++;
            }
        }
    }
    if (tileCount == 25 * 16 - mineCount) {
        for (unsigned int i = 0; i < 25; i++) {
            for (unsigned int j = 0; j < 16; j++) {
                if (tileGrid[i][j]->hasMine == false) {
                    tileGrid[i][j]->setState(revealed);
                } else {
                    tileGrid[i][j]->flag->state = revealed;
                }
            }
        }
        return true;
    }
    return false;
}

void Board::loadMines(unsigned int i) {
    mineCount = 0;
    bool minePlaces[25 * 16];
    for (unsigned int i = 0; i < 25; i++) {
        for (unsigned int j = 0; j < 16; j++) {
            mineGrid[i][j] = nullptr;
        }
    }
    
    for (unsigned int i = 0; i < 25 * 16; i++) {
        minePlaces[i] = 0;
    }
    
    std::ifstream file("./boards/testboard" + std::to_string(i) + ".brd");
    int count = 0;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            for (char each : line) {
                if (each == '1') {
                    minePlaces[count] = true;
                } else if (each == '0') {
                    minePlaces[count] = false;
                } else {
                    continue;
                }
                count++;
            }
        }
        file.close();
    }
    
    count = 0;
    for (unsigned int j = 0; j < 16; j++) {
        for (unsigned int i = 0; i < 25; i++) {
            if (minePlaces[count] == true) {
                mineGrid[i][j] = new Mine(i * 32, j * 32);
                mineCount++;
            }
            count++;
        }
    }
}

void Board::setDebug() {
    if (desiredState == hidden) {
        desiredState = revealed;
        wasInDebug = false;
    } else {
        desiredState = hidden;
        wasInDebug = true;
    }
}
