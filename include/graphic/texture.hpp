#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "SDL.h"
#include <string>

using std::string;

/**
 * Texture
 */
class Texture
{
  public:
    Texture(SDL_Renderer *renderer)
        : mRenderer(renderer), mTexture(NULL), mWidth(0), mHeight(0) {}

    ~Texture()
    {
        free();
    }

    bool loadFromFile(string path);
    void free();

    void render(int x, int y, SDL_Rect *clip = NULL);
    int getWidth() { return mWidth; }
    int getHeight() { return mHeight; }

  private:
    SDL_Renderer *mRenderer;
    SDL_Texture *mTexture;
    int mWidth;
    int mHeight;
};

#endif // TEXTURE_HPP
