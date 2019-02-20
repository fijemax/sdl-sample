#ifndef CORE_CORE_HPP
#define CORE_CORE_HPP

#include <string>
#include <core/window_manager.hpp>
#include <graphic/sprites_loader.hpp>

using std::string;

/**
 * Core game
 */
class Core
{
public:
  Core(std::string *assetsPath)
      : mRun(false),
        mAssetsPath(assetsPath),
        mWindowManager(assetsPath),
        mTimer() {}
  ~Core() {}

  int startGame();

private:
  int initMedia();
  void stopMedia();
  int gameLoop();

  bool mRun;
  string *mAssetsPath;
  WindowManager mWindowManager;
  Timer mTimer;
};

#endif // CORE_CORE_HPP