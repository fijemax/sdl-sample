#include <graphic/sprite.hpp>

void Sprite::render(int timestamp, int x, int y, double angle, SDL_Point *center, SDL_RendererFlip flip)
{
    int spriteIndex = (timestamp / mFrameDuration) % mSpriteClipArraySize;
    Texture::render(x, y, &mSpriteClipArray[spriteIndex], angle, center, flip);
}

bool Sprite::load()
{
    if (!Texture::load())
    {
        return false;
    }

    mSpriteWidth = mWidth / mMatrixN;
    mSpriteHeight = mHeight / mMatrixM;

    mSpriteClipArray = new SDL_Rect[mSpriteClipArraySize];
    mFrameDuration = mDuration / mSpriteClipArraySize;

    for (int m = 0, index = 0; m < mMatrixM; m++)
    {
        for (int n = 0; n < mMatrixN; n++, index++)
        {
            mSpriteClipArray[index].x = mSpriteWidth * n;
            mSpriteClipArray[index].y = mSpriteHeight * m;
            mSpriteClipArray[index].w = mSpriteWidth;
            mSpriteClipArray[index].h = mSpriteHeight;
        }
    }
    return true;
}