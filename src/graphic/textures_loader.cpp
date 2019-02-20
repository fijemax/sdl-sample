#include "graphic/textures_loader.hpp"
#include "graphic/texture.hpp"
#include "graphic/sprite.hpp"

TexturesLoader::TexturesLoader(SDL_Renderer *renderer,
                               string assetPath,
                               vector<TextureDef> &textureDefs)
    : mAssetPath(assetPath),
      mTexturesMap()
{
    for (TextureDef def : textureDefs)
    {
        mTexturesMap[def.id] = make_unique<Texture>(renderer,
                                                    mAssetPath + string(def.path));
    }
};

TexturesLoader::~TexturesLoader() {}

bool TexturesLoader::loads()
{
    bool res = true;
    map<TextureType, unique_ptr<Texture>>::iterator it;
    for (it = mTexturesMap.begin(); it != mTexturesMap.end(); it++)
    {
        if (!it->second->load())
        {
            res = false;
        }
    }
    return res;
}

void TexturesLoader::render(TextureType type,
                            int x,
                            int y,
                            SDL_Rect *clip,
                            double angle,
                            SDL_Point *center,
                            SDL_RendererFlip flip)
{
    return mTexturesMap[type]->render(x, y, clip, angle, center, flip);
}
