#ifndef TEXTURES_LOADER_HPP
#define TEXTURES_LOADER_HPP

#include <graphic/texture.hpp>
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
 * TextureDef
 * Contain informations to create, store and load texture
 */
struct TextureDef
{
  const TextureType id;
  const char *path;
};

/**
 * TexturesLoader
 * Create, store and load texture animation
 */
class TexturesLoader
{
public:
  TexturesLoader(SDL_Renderer *renderer,
                 string assetPath,
                 vector<TextureDef> &mSpritesDef);
  ~TexturesLoader();

  bool loads();

  void render(TextureType type,
              int x,
              int y,
              SDL_Rect *clip,
              double angle,
              SDL_Point *center,
              SDL_RendererFlip flip);

private:
  string mAssetPath;
  map<TextureType, unique_ptr<Texture>> mTexturesMap;
};

#endif // TEXTURES_LOADER_HPP
