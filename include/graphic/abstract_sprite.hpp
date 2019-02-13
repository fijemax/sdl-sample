#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <string>
#include <graphic/texture.hpp>

/**
 * Sprite
 */
class AbstractSprite : public Texture
{
public:
  AbstractSprite(SDL_Renderer *renderer) : Texture(renderer) {}

  void render(int x, int y, uint32_t spriteIndex);

  virtual SDL_Rect *getSpriteClips() = 0;
  virtual uint32_t getSpriteClipsNumber() = 0;
};

#endif // SPRITE_HPP