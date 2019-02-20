#ifndef SPRITES_LOADER_HPP
#define SPRITES_LOADER_HPP

#include <graphic/sprite.hpp>
#include <graphic/type.hpp>

#include <map>
#include <memory>
#include <string>
#include <vector>

using std::make_unique;
using std::map;
using std::unique_ptr;
using std::vector;

/**
 * SpriteDef
 * Contain informations to create, store and load sprite animation
 */
struct SpriteDef
{
  const SpriteType id;
  const char *path;
  const uint m;
  const uint n;
  const uint duration;
};

/**
 * SpritesLoader
 * Create, store and load sprite animation
 */
class SpritesLoader
{
public:
  SpritesLoader(SDL_Renderer *renderer,
                string assetPath,
                vector<SpriteDef> &mSpritesDef);
  ~SpritesLoader();

  bool loads();

  void render(SpriteType type,
              int timestamp,
              int x,
              int y,
              double angle,
              SDL_Point *center,
              SDL_RendererFlip flip);

private:
  string mAssetPath;
  map<SpriteType, unique_ptr<Sprite>> mSpritesMap;
};

#endif // SPRITES_LOADER_HPP
