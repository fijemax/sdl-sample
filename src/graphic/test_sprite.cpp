#include "graphic/test_sprite.hpp"

SDL_Rect *TestSprite::getSpriteClips()
{
    return gSpriteClips;
}

uint32_t TestSprite::getSpriteClipsNumber()
{
    return WALKING_ANIMATION_FRAMES;
}