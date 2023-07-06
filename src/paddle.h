#ifndef PADDLE_H_
#define PADDLE_H_

#include "utils.h"

class Paddle {

public:
    Paddle(int i);    // i is for id?

    void Update();
    
    void SetDir(int d);    // setter for private dir below, used to move paddle in game.c handleevents()
    
    SDL_Rect *GetRect();    // getter to get private rect below, used in paddle.c getrect()


private:
    int id;
    int dir = 0;
    int width = 20;
    int height = 140;
    float x, y, speed;

    SDL_Rect rect;


};

#endif  // PADDLE_H_
