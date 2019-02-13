#ifndef TEST_SPRITE_HPP
#define TEST_SPRITE_HPP

#include <string>
#include <graphic/abstract_sprite.hpp>

/**
 * Sprite
 */
class TestSprite : public AbstractSprite
{
  public:
    bool load(string path)
    {
        return Texture::loadFromFile(path);
    }

    TestSprite(SDL_Renderer *renderer) : AbstractSprite(renderer)
    {
        gSpriteClips[0].x = 0;
        gSpriteClips[0].y = 0;
        gSpriteClips[0].w = 64;
        gSpriteClips[0].h = 205;

        gSpriteClips[1].x = 64;
        gSpriteClips[1].y = 0;
        gSpriteClips[1].w = 64;
        gSpriteClips[1].h = 205;

        gSpriteClips[2].x = 128;
        gSpriteClips[2].y = 0;
        gSpriteClips[2].w = 64;
        gSpriteClips[2].h = 205;

        gSpriteClips[3].x = 196;
        gSpriteClips[3].y = 0;
        gSpriteClips[3].w = 64;
        gSpriteClips[3].h = 205;
    }

    SDL_Rect *getSpriteClips();
    uint32_t getSpriteClipsNumber();

  private:
    const int WALKING_ANIMATION_FRAMES = 4;
    SDL_Rect gSpriteClips[4];
};

#endif // TEST_SPRITE_HPP
