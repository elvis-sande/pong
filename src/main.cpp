#include "game.h"

int main(int argc, char *argv[])
{
    Game game;    // instantiate game object

    if (game.Init()) {    // If game initializes,
        game.GameLoop();  // start gameloop method
    }

    game.ShutDown();

    return 0;
}
