#ifndef BALL_H_
#define BALL_H_

#include "paddle.h"

class Ball {

public:
    Ball();

    void Update(Paddle *lPaddle, Paddle *rPaddle);

    void HandleCollision(Paddle *paddle);

    bool BottomCollision(Paddle *paddle);
    bool TopCollision(Paddle *paddle);

    SDL_Rect *GetRect();    // getter to get private rect below, used in paddle.c getrect()


private:
    int dir = 0;
    int size = 20;
    float speed;
    const int INITIAL_SPEED = 6.f;
    const int MAX_SPEED = 12.f;


    Vec2 pos;
    Vec2 vel;

    SDL_Rect rect;

};

#endif // BALL_H_