#include "ball.h"
#include "utils.h"
#include "paddle.h"

Ball::Ball() {
    speed = INITIAL_SPEED;

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
    pos.y += vel.y * speed;
    pos.x += vel.x * speed;

    HandleCollision(lPaddle);
    HandleCollision(rPaddle);

    // Bounce ball differently depending on where it hits the paddle 
    int middlePaddleY = paddle->GetPos().y + paddle->GetRect()->h / 2;
    int middleBallY = pos.y + size / 2;
    int offsetY = middlePaddleY - middleBallY;

    vel.y -= offsetY * 1.5 / 100.f;

    // ball top-bottom bounds collision (keep ball inbound)
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

bool Ball::BottomCollision(Paddle *paddle) {
    bool passedBound = false;    // ball has exited screen width
    bool collided = false;

    if (paddle->GetId() == 0) {                     // check if lPad < 20
        passedBound = pos.x < size;
    }
    else if (paddle->GetId() == 1) {
        passedBound = pos.x > SCREEN_WIDTH - size;
    }

    if (passedBound                                                        // passed outer bound of paddle
        && pos.y <= paddle->GetRect()->y + paddle->GetRect()->h            // top of ball is inside bottom of paddle
        && pos.y + size > paddle->GetRect()->y + paddle->GetRect()->h      // bottom of ball ! inside bottom of paddle
        && vel.y < 0) {                                                    // ball is moving
            pos.y = paddle->GetRect()->y + paddle->GetRect()->h + 1;       // give a buffer of 1px so doesn't intersect immediately
            vel.y *= -1;      // invert y (bounce)
            rect.y = pos.y;   // ball do not go past current pos

            collided = true;
        }
        
        return collided;
}

bool Ball::TopCollision(Paddle *paddle) {
    bool passedBound = false;    // ball has exited screen width
    bool collided = false;

    if (paddle->GetId() == 0) {                     // check if lPad < 20
        passedBound = pos.x < size;
    }
    else if (paddle->GetId() == 1) {
        passedBound = pos.x > SCREEN_WIDTH - size;
    }

    if (passedBound                                                        // passed outer bound of paddle
        && pos.y + size >= paddle->GetRect()->y                            // bottom of ball is inside top of paddle
        && pos.y < paddle->GetRect()->y                                    // top of ball ! inside top of paddle
        && vel.y > 0) {                                                    // ball is moving
            pos.y = paddle->GetRect()->y - size -1;                        // give a buffer of 1px so doesn't intersect immediately
            vel.y *= -1;      // invert y (bounce)
            rect.y = pos.y;   // ball do not go past current pos

            collided = true;
        }
        
        return collided;
}

void Ball::HandleCollision(Paddle *paddle) {

    if (BottomCollision(paddle) || TopCollision(paddle)) {
        return;
    }

    if ((   pos.x + size) >= paddle ->GetPos().x                           // if right side of ball touches left side of paddle,
         && pos.x <= paddle ->GetPos().x + paddle -> GetRect() -> w     // and left side of ball touches right side of paddle,
         && (pos.y + size) >= paddle -> GetPos().y                      // and bottom side of ball touches top of paddle,
         && pos.y <= paddle -> GetPos().y + paddle -> GetRect() -> h) { // and top side of ball touches bottom side of paddle   
            vel.x *= -1;

            // bounce ball differently depending on where it hits the paddle
            int middlePaddleY = paddle->GetPos().y + paddle->GetRect()->h / 2;
            int middleBallY = pos.y + size / 2;
            int offsetY = middlePaddleY - middleBallY;

            vel.y -= offsetY * 1.5 / 100.f; 
            
            if (paddle -> GetId() == 0) {
                pos.x = paddle -> GetPos().x + paddle -> GetRect() -> w;
            }
            else if (paddle -> GetId() == 1) {
                pos.x = paddle ->GetPos().x - size;
            }

            if (speed < MAX_SPEED) { speed++; }
            
    }
};


SDL_Rect *Ball::GetRect() { return &rect; }