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
  Texture(SDL_Renderer *renderer, string path)
      : mRenderer(renderer), mTexturePath(path), mTexture(NULL), mWidth(0), mHeight(0) {}

  ~Texture()
  {
    fprintf(stdout, "Free texture %s\n", mTexturePath.c_str());
    free();
  }

  bool load();
  void free();

  void render(int x,
              int y,
              SDL_Rect *clip,
              double angle,
              SDL_Point *center,
              SDL_RendererFlip flip);
  int getWidth() { return mWidth; }
  int getHeight() { return mHeight; }

protected:
  int mWidth;
  int mHeight;
  string mTexturePath;

private:
  SDL_Renderer *mRenderer;
  SDL_Texture *mTexture;
};

#endif // TEXTURE_HPP
