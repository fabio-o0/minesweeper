//
//  Tile.cpp
//  Minesweeper
//
//  Created by Fabio Suarez on 11/24/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#include <stdio.h>
#include "Tile.h"

Tile::Tile() {
    this->flag = new Flag();
    this->state = hidden;
    this->hasMine = false;
    GameObject::setTexture("./images/tile_hidden.png");
    setSprite();
    this->counter = new MineCounter();
}

Tile::Tile(State state, Vector2f position, bool hasMine) {
    this->flag = new Flag(position);
    this->state = state;
    this->hasMine = hasMine;
    setPosition(position);
    if (state == hidden) {
        GameObject::setTexture("./images/tile_hidden.png");
    } else {
        GameObject::setTexture("./images/tile_revealed.png");
    }
    setSprite();
    this->counter = new MineCounter(position.x, position.y);
}

Tile::Tile(State state, float x, float y, bool hasMine) {
    this->flag = new Flag(x, y);
    this->state = state;
    this->hasMine = hasMine;
    setPosition(x, y);
    if (state == hidden) {
        GameObject::setTexture("./images/tile_hidden.png");
    } else {
        GameObject::setTexture("./images/tile_revealed.png");
    }
    setSprite();
    this->counter = new MineCounter(x, y);
}

void Tile::setState(State state) {
    this->state = state;
    this->setTexture(state);
}

void Tile::setHasMine(bool hasMine) {
    this->hasMine = hasMine;
}

void Tile::setTexture(State state) {
    if (state == hidden) {
        GameObject::setTexture("./images/tile_hidden.png");
    } else if (state == revealed) {
        GameObject::setTexture("./images/tile_revealed.png");
    }
}


void Tile::uncoverAdjacent() {
    int count = 0;
    for (unsigned int i = 0; i < adjacentTiles.size(); i++) {
        if (adjacentTiles[i]->hasMine) {
            count++;
        }
    }
    if (count != 0) {
        this->counter->setCount(count);
        this->counter->position = position;
    } else {
        for (unsigned int i = 0; i < adjacentTiles.size(); i++) {
            if (adjacentTiles[i]->state == hidden) {
                for (unsigned int j = 0; j < adjacentTiles[i]->adjacentTiles.size(); j++) {
                    if (adjacentTiles[i]->adjacentTiles[j]->hasMine == false) {
                        if (adjacentTiles[i]->flag->state != revealed) {
                            adjacentTiles[i]->setState(revealed);
                            adjacentTiles[i]->uncoverAdjacent();
                        }
                    }
                }
            }
        }
    }
}

Tile::~Tile() {
    delete flag;
    delete counter;
}
