#ifndef PADDLE_H_
#define PADDLE_H_

#include "utils.h"

class Paddle {

public:
    Paddle(int i);    // i is for id?

    void Update();
    
    void SetDir(int d);    // setter for private direction below, used to move paddle in game.c handleevents()
    
    int GetId();

    SDL_Rect *GetRect();    // getter to get private rect below, used in paddle.c getrect()

    Vec2 GetPos();          // added to check paddle-ball collision

private:
    int id;
    int dir = 0;
    int width = 20;
    int height = 140;
    float speed;

    Vec2 pos;
    
    SDL_Rect rect;

};

#endif  // PADDLE_H_
