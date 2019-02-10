#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "core/core.hpp"
#include "SDL.h"
#include "SDL_image.h"

using std::string;

int core_init(string *assets_path)
{
    /* Initialisation simple */ if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stdout, "Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
        return -1;
    }

    {
        /* Création de la fenêtre */
        SDL_Window *pWindow = NULL;
        SDL_Renderer *pMainRenderer;
        SDL_Surface *pLoadingSurf;
        SDL_Texture *pBackgroundTx;
        SDL_Texture *pBlueShapes;

        pWindow = SDL_CreateWindow("Ma première application SDL2", SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   2048,
                                   480,
                                   SDL_WINDOW_RESIZABLE);

        pMainRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
        // pLoadingSurf = SDL_LoadBMP("background.bmp");
        string bck("/background.jpg");
        string bckgPath = (*assets_path).append(bck);
        pLoadingSurf = IMG_Load(bckgPath.c_str());
        pBackgroundTx = SDL_CreateTextureFromSurface(pMainRenderer, pLoadingSurf);
        SDL_FreeSurface(pLoadingSurf); /* we got the texture now -> free surface */

        SDL_RenderCopy(pMainRenderer, pBackgroundTx, NULL, NULL);
        SDL_RenderPresent(pMainRenderer);

        if (pWindow)
        {
            SDL_Delay(10000); /* Attendre trois secondes, que l'utilisateur voie la fenêtre */

            SDL_DestroyWindow(pWindow);
        }
        else
        {
            fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
        }
    }

    SDL_Quit();

    return 0;
}