#ifndef SCENE_HPP
#define SCENE_HPP

#include <world/camera.hpp>

#include <graphic/type.hpp>

#include "Box2D/Box2D.h"
#include "SDL.h"

/**
 * Scene
 */
class Scene
{
public:
  Scene(const b2Vec2 &gravity)
      : mWorld(gravity),
        texture(NIGHT),
        mX(150),
        mY(150){};

  ~Scene(){};
  void getCenter(int &x, int &y)
  {
    x = mX;
    y = mY;
  };

  void setCenter(const int x, const int y)
  {
    mX = x;
    mY = y;
  };

private:
  const b2World mWorld;
  const TextureType texture;
  int mX, mY;
};

#endif // SCENE_HPP