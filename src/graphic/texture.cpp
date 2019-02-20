#include "graphic/texture.hpp"
#include "SDL.h"
#include "SDL_image.h"

bool Texture::load()
{
    free(); // Free before all
    SDL_Surface *loadedSurface = IMG_Load(mTexturePath.c_str());
    if (loadedSurface == NULL)
    {
        fprintf(stderr, "Unable to load image %s! SDL_image Error: %s\n", mTexturePath.c_str(), IMG_GetError());
    }
    else
    {
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));
        mTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
        if (mTexture == NULL)
        {
            fprintf(stderr, "Unable to create texture from %s! SDL Error: %s\n", mTexturePath.c_str(), SDL_GetError());
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

void Texture::render(int x,
                     int y,
                     SDL_Rect *clip,
                     double angle,
                     SDL_Point *center,
                     SDL_RendererFlip flip)
{
    SDL_Rect renderQuad = {x, y, mWidth, mHeight};
    if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopyEx(mRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}