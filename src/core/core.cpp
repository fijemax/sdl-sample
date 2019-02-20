#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "core/core.hpp"

#include "SDL.h"
#include "SDL_image.h"

#include "graphic/sprites_loader.hpp"

using std::string;

int Core::startGame()
{
    // Init SDL
    int res = initMedia();
    if (res != 0)
        return res;

    res = mWindowManager.start();
    if (res != 0)
        return res;

    mTimer.start();

    res = gameLoop();

    // Quit windows manager
    mWindowManager.stop();

    // Quit SDL
    stopMedia();

    return res;
}

int Core::initMedia()
{
    fprintf(stdout, "Init media\n");

    /* SDL init */
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
        return -1;
    }

    // SDL image init
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        fprintf(stderr, "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return -1;
    }
    return 0;
}

void Core::stopMedia()
{
    fprintf(stdout, "Stop media\n");
    IMG_Quit();
    SDL_Quit();
}

int Core::gameLoop()
{
    fprintf(stdout, "Enter game loop\n");

    int res = -1;
    mRun = true;
    while (mRun)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0)
        {
            switch (e.type)
            {
            case SDL_QUIT:
                res = 0;
                mRun = false;
                break;
            default:
                break;
            }
        }
        res = mWindowManager.renderScene(mTimer.getTicks());
        if (res != 0)
            break;
    }

    fprintf(stdout, "Exit game loop\n");

    if (res != 0)
        printf("Game not close properly\n");

    return res;
}