//
//  MainButton.cpp
//  Minesweeper
//
//  Created by Fabio Suarez on 11/25/19.
//  Copyright © 2019 Fabio Suarez. All rights reserved.
//

#include <stdio.h>
#include "MainButton.h"

MainButton::MainButton() : Button() {
    this->kind = happy;
    if (kind == happy) {
        setTexture("./images/face_happy.png");
    } else if (kind == win) {
        setTexture("./images/face_win.png");
    }
    else if (kind == lose) {
        setTexture("./images/face_lose.png");
    }
    setSprite();
}

MainButton::MainButton(Vector2f position, Kind kind) {
    this->kind = kind;
    setPosition(position);
    if (kind == happy) {
        setTexture("./images/face_happy.png");
    } else if (kind == win) {
        setTexture("./images/face_win.png");
    }
    else if (kind == lose) {
        setTexture("./images/face_lose.png");
    }
    setSprite();
}

MainButton::MainButton(float x, float y, Kind kind) {
    this->kind = kind;
    setPosition(x, y);
    if (kind == happy) {
        setTexture("./images/face_happy.png");
    } else if (kind == win) {
        setTexture("./images/face_win.png");
    }
    else if (kind == lose) {
        setTexture("./images/face_lose.png");
    }
    setSprite();
}

void MainButton::setKind(Kind kind) {
    this->kind = kind;
    if (kind == happy) {
        setTexture("./images/face_happy.png");
    } else if (kind == win) {
        setTexture("./images/face_win.png");
    }
    else if (kind == lose) {
        setTexture("./images/face_lose.png");
    }
    setSprite();
}

