#ifndef PADDLE_H_
#define PADDLE_H_

#include "utils.h"

class Paddle {

public:
    Paddle(int i);    // i is for id?

    void Update();
    
    SDL_Rect *GetRect();    // getter to get private rect below


private:
    int id;
    int dir = 0;
    int width = 20;
    int height = 100;
    float x, y, speed;

    SDL_Rect rect;


};

#endif  // PADDLE_H_
