#ifndef CORE_CORE_HPP
#define CORE_CORE_HPP

#include <string>
#include <graphic/window_manager.hpp>

using std::string;

/**
 * Core game
 */
class Core
{
public:
  Core(std::string *assetsPath) : mIsStart(false), mAssetsPath(assetsPath), mWindowManager(assetsPath) {}
  int startGame();

private:
  string *mAssetsPath;
  bool mIsStart;
  WindowManager mWindowManager;
};

#endif // CORE_CORE_HPP