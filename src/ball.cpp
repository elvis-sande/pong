#include "ball.h"
#include "utils.h"

Ball::Ball() {
    speed = 8.f;

    pos.x = SCREEN_WIDTH / 2 - size / 2;
    pos.y = SCREEN_HEIGHT / 2 - size / 2;

    vel.x = 1;    // vel 1x = right
    vel.y = 1;    // vel 1y = down

    rect.x = (int)pos.x;
    rect.y = (int)pos.y;
    rect.w = size;
    rect.h = size;

};

void Ball::Update(Paddle *lPaddle, Paddle *rPaddle) {
    pos.y += (vel.y * speed);
    pos.x += (vel.x * speed);

    HandleCollision(lPaddle);
    HandleCollision(rPaddle);

    // ball top-bottom bounds collision
    if (pos.y < 0){
        pos.y = 0;
        vel.y *= -1;
        }
    else if ((pos.y + size) > SCREEN_HEIGHT) {
        pos.y = SCREEN_HEIGHT - size;
        vel.y *= -1;
        }

    rect.x = (int)pos.x;
    rect.y = (int)pos.y;
}

void Ball::HandleCollision(Paddle *paddle) {
    if ((   pos.x + size) >= paddle ->GetPos().x                           // if right side of ball touches left side of paddle,
         && pos.x <= paddle ->GetPos().x + paddle -> GetRect() -> w     // and left side of ball touches right side of paddle,
         && (pos.y + size) >= paddle -> GetPos().y                      // and bottom side of ball touches top of paddle,
         && pos.y <= paddle -> GetPos().y + paddle -> GetRect() -> h) { // and top side of ball touches bottom side of paddle   
            vel.x *= -1;
            
            if (paddle -> GetId() == 0) {
                pos.x = paddle -> GetPos().x + paddle -> GetRect() -> w;
            }
            else if (paddle -> GetId() == 1) {
                pos.x = paddle ->GetPos().x - size;
            }
            
    }
};

void Ball::SetVel(float x, float y) {};

void Ball::invertXVel() {  }

SDL_Rect *Ball::GetRect() { return &rect; }