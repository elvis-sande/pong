#ifndef GAME_H_
#define GAME_H_

#include "paddle.h"

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

    // Paddle stuff added here idk y
    class Paddle *leftPaddle, *rightPaddle;

};

#endif // GAME_H_
