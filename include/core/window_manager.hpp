#ifndef WINDOWS_MANAGER_HPP
#define WINDOWS_MANAGER_HPP

#include "SDL.h"
#include "SDL_image.h"
#include "Box2D/Box2D.h"
#include "graphic/sprites_loader.hpp"
#include "graphic/textures_loader.hpp"
#include "world/scene.hpp"
#include "util/timer.hpp"

#include <string>

using std::string;

/**
 * WindowManager
 */
class WindowManager
{
public:
  WindowManager(std::string *assetsPath)
      : mAssetsPath(assetsPath),
        mScene(b2Vec2(0, 9.8)){};
  ~WindowManager(){};

  SDL_Renderer *getSDLSceneRenderer()
  {
    return mSceneRenderer;
  }
  int start();
  void stop();
  int renderScene(int timestamp);

private:
  string *mAssetsPath;
  SDL_Window *mWindow;
  SDL_Renderer *mSceneRenderer;
  SpritesLoader *mSpritesLoader;
  TexturesLoader *mTexturesLoader;
  Scene mScene;
};

#endif // WINDOWS_MANAGER_HPP