//
//  GameObject.cpp
//  Minesweeper
//
//  Created by Fabio Suarez on 11/24/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#include <stdio.h>
#include "GameObject.h"

void GameObject::setTexture(Texture texture) {
    this->texture = texture;
    setSprite();
}

void GameObject::setSprite() {
    this->sprite = Sprite(this->texture);
    this->sprite.setPosition(this->position.x, this->position.y);
}

void GameObject::setTexture(std::string textureFile) {
    try {
        this->texture.loadFromFile(textureFile);
    } catch (std::exception e) {}
    setSprite();
}

void GameObject::setPosition(Vector2f position) {
    this->position = position;
}

void GameObject::setPosition(float x, float y) {
    this->position.x = x;
    this->position.y = y;
}
