#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <string>
#include <graphic/texture.hpp>

/**
 * Sprite
 */
class Sprite : public Texture
{
public:
  Sprite(SDL_Renderer *renderer,
         string spritePath,
         uint matrixM,
         uint matrixN,
         uint duration)
      : Texture(renderer, spritePath),
        mMatrixM(matrixM),
        mMatrixN(matrixN),
        mSpriteWidth(0),
        mSpriteHeight(0),
        mDuration(duration),
        mSpriteClipArraySize(matrixM * matrixN) {}

  ~Sprite()
  {
    if (mSpriteClipArray)
    {
      delete[] mSpriteClipArray;
    }
  }

  void render(int timestamp, int x, int y, double angle, SDL_Point *center, SDL_RendererFlip flip);
  uint getSpriteWidth() { return mSpriteWidth; }
  uint getSpriteHeight() { return mSpriteHeight; }
  bool load();

private:
  uint mDuration;
  uint mSpriteWidth, mSpriteHeight;
  uint mMatrixM, mMatrixN;
  uint mFrameDuration;
  uint mSpriteClipArraySize;
  SDL_Rect *mSpriteClipArray;
};

#endif // SPRITE_HPP