#include "game.h"
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>

bool Game::Init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return false;
    }
    
    window = SDL_CreateWindow("pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!window) {
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        return false;
    }

    // Init-xion of paddles
    leftPaddle = new Paddle(0);
    rightPaddle = new Paddle(1);

    return true;

}

void Game::GameLoop() {
    while (isRunning) {
        HandleEvents();
        Update();
        Draw();
    }
}

void Game::HandleEvents(){
    SDL_Event event;

    const Uint8* keystates = SDL_GetKeyboardState(NULL);  // NULL is all keys

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT || keystates[SDL_SCANCODE_ESCAPE]) {
            isRunning = false;
        }
    }


}

void Game::Update() {}

void Game::Draw() {
    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
    SDL_RenderClear(renderer);

    // Draw paddles
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, leftPaddle -> GetRect());

    SDL_RenderPresent(renderer);
}

void Game::ShutDown() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}