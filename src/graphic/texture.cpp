#include "graphic/texture.hpp"
#include "SDL.h"
#include "SDL_image.h"

bool Texture::loadFromFile(string path)
{
    free(); // Free before all
    SDL_Texture *newTexture = NULL;
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        fprintf(stdout, "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        mTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
        if (mTexture == NULL)
        {
            fprintf(stdout, "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        else
        {
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }
        SDL_FreeSurface(loadedSurface);
    }
    return mTexture != NULL;
}

void Texture::free()
{
    if (mTexture != NULL)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void Texture::render(int x, int y, SDL_Rect *clip)
{
    SDL_Rect renderQuad = {x, y, mWidth, mHeight};
    if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    // SDL_RenderCopyEx
    SDL_RenderCopy(mRenderer, mTexture, clip, &renderQuad);
}
