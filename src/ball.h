#ifndef BALL_H_
#define BALL_H_

#include "paddle.h"

class Ball {

public:
    Ball();

    void Update(Paddle *lPaddle, Paddle *rPaddle);
    
    void SetVel(float x, float y);    // setter for private dir below, used to move paddle in game.c handleevents()
    void invertXVel();

    void HandleCollision(Paddle *paddle);

    bool BottomCollision(Paddle *paddle);
    bool TopCollision(Paddle *paddle);

    SDL_Rect *GetRect();    // getter to get private rect below, used in paddle.c getrect()


private:
    int dir = 0;
    int size = 20;
    float speed;
    const int INITIAL_SPEED = 7;
    const int MAX_SPEED = 12;


    Vec2 pos;
    Vec2 vel;

    SDL_Rect rect;

};

#endif // BALL_H_