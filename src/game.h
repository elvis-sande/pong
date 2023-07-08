#ifndef GAME_H_
#define GAME_H_

#include "paddle.h"
#include "ball.h"

class Game {

public:
    bool Init();
    void GameLoop();
    void ShutDown();

private:
    void HandleEvents();
    void Update();
    void Draw();

    bool isRunning = true;
    
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    // Paddle & ball pointers added here idk y
    class Paddle *leftPaddle, *rightPaddle;
    class Ball *ball;

};

#endif // GAME_H_
