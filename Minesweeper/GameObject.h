//
//  GameObject.h
//  Minesweeper
//
//  Created by Fabio Suarez on 11/24/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class GameObject {
private:
public:
    Vector2f position;
    Texture texture;
    Sprite sprite;
    void setTexture(Texture texture);
    void setTexture(std::string textureFile);
    void setPosition(Vector2f position);
    void setPosition(float x, float y);
    void setSprite();
};
