#include "graphic/sprites_loader.hpp"

SpritesLoader::SpritesLoader(SDL_Renderer *renderer,
                             string assetPath,
                             vector<SpriteDef> &mSpritesDef)
    : mAssetPath(assetPath),
      mSpritesMap()
{
    for (SpriteDef def : mSpritesDef)
    {
        mSpritesMap[def.id] = make_unique<Sprite>(renderer,
                                                  mAssetPath + string(def.path),
                                                  def.m,
                                                  def.n,
                                                  def.duration);
    }
};

SpritesLoader::~SpritesLoader() {}

bool SpritesLoader::loads()
{
    bool res = true;
    map<SpriteType, unique_ptr<Sprite>>::iterator it;
    for (it = mSpritesMap.begin(); it != mSpritesMap.end(); it++)
    {
        if (!it->second->load())
        {
            res = false;
        }
    }
    return res;
}

void SpritesLoader::render(SpriteType type,
                           int timestamp,
                           int x,
                           int y,
                           double angle,
                           SDL_Point *center,
                           SDL_RendererFlip flip)
{
    mSpritesMap[type]->render(timestamp, x, y, angle, center, flip);
}
