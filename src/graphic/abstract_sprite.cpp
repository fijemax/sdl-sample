#include <graphic/abstract_sprite.hpp>

void AbstractSprite::render(int x, int y, uint32_t spriteIndex)
{
    if (spriteIndex >= getSpriteClipsNumber())
    {
        fprintf(stderr, "Render error: sprite index %d but sprite index max : %d\n", spriteIndex, getSpriteClipsNumber() - 1);
    }
    SDL_Rect *arr = getSpriteClips();
    Texture::render(x, y, &arr[spriteIndex]);
}
