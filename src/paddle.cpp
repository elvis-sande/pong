#include "paddle.h"

Paddle::Paddle(int i) {
    id = i;
    speed = 20.f;

    switch (id) {
        case 0:                           // left paddle
            x = 0;
            break;
        case 1:                           // right paddle
            x = SCREEN_WIDTH - width;
            break;
    };
    y = (SCREEN_HEIGHT / 2) - (height / 2);

    rect.x = (int)x;
    rect.y = (int)y;
    
    rect.w = width;
    rect.h = height;

}

void Paddle::Update() {
    y += (speed * dir);

    rect.y = y;    // sync y value
};

void Paddle::SetDir(int d) {
    dir = d;
};

SDL_Rect *Paddle::GetRect() {
    return &rect;             // provides access to private rect member
};
