#include "paddle.h"

Paddle::Paddle(int i) {
    id = i;
    speed = 15.f;

    switch (id) {
        case 0:                           // left paddle
            pos.x = 0;
            break;
        case 1:                           // right paddle
            pos.x = SCREEN_WIDTH - width;
            break;
    };
    pos.y = (SCREEN_HEIGHT / 2) - (height / 2);

    rect.x = (int)pos.x;
    rect.y = (int)pos.y;
    
    rect.w = width;
    rect.h = height;

}

void Paddle::Update() {
    pos.y += (speed * dir);      // set initial y val

    if (pos.y < 0){             // collision
        pos.y = 0;
        }
    else if ((pos.y + height) > SCREEN_HEIGHT) {
        pos.y = SCREEN_HEIGHT - height;
        }

    rect.y = pos.y;             // sync y value
}

void Paddle::SetDir(int d) { dir = d; }

int Paddle::GetId() { return id; }

Vec2 Paddle::GetPos() { return pos; }    // for paddle-ball collision

SDL_Rect *Paddle::GetRect() {
    return &rect;             // provides access to private rect member
};
