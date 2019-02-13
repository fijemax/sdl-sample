#include <graphic/window_manager.hpp>
#include "SDL.h"
#include "SDL_image.h"
#include "graphic/texture.hpp"
#include "graphic/test_sprite.hpp"

int WindowManager::init()
{
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
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return -1;
    }
    return 0;
}

int WindowManager::display()
{
    /* Création de la fenêtre */
    SDL_Window *pWindow = NULL;
    SDL_Renderer *pMainRenderer;
    SDL_Surface *pLoadingSurf;
    SDL_Texture *pBackgroundTx;

    pWindow = SDL_CreateWindow("Ma première application SDL2", SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               500,
                               322,
                               SDL_WINDOW_RESIZABLE);

    pMainRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (pWindow)
    {
        TestSprite testSprite(pMainRenderer);
        string sprite_path = (*mAssetsPath).append("foo.png");

        int frame = 0;
        if (/*texture.loadFromFile(bckgPath */ testSprite.load(sprite_path))
        {
            SDL_Event e;
            mRun = true;

            while (mRun)
            {
                while (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT)
                    {
                        mRun = false;
                    }
                }

                SDL_SetRenderDrawColor(pMainRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(pMainRenderer);
                // SDL_Rect rect = {0, 0, SDL_GetWindowSurface(pWindow)->w, SDL_GetWindowSurface(pWindow)->h};
                // texture.render(0, 0, &rect);
                testSprite.render(SDL_GetWindowSurface(pWindow)->w / 2, SDL_GetWindowSurface(pWindow)->h / 2, frame / 6);
                ++frame;
                if (frame / 6 >= testSprite.getSpriteClipsNumber())
                {
                    frame = 0;
                }

                SDL_RenderPresent(pMainRenderer);
            }
        }
        SDL_DestroyWindow(pWindow);
    }
    else
    {
        fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
    }

    SDL_Quit();
    return 0;
}