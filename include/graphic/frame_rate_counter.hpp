#ifndef FRAME_RATE_COUNTER_HPP
#define FRAME_RATE_COUNTER_HPP

#include "util/timer.hpp"

/**
 * FrameRateCounter
 */
class FrameRateCounter
{
public:
  FrameRateCounter(int screenFPS = 60) : SCREEN_FPS(screenFPS), SCREEN_TICKS_PER_FRAME(1000 / SCREEN_FPS), mTimer() {}
  int getScreenFPS() { return SCREEN_FPS; }
  int getScreenTicksPerFrame() { return SCREEN_TICKS_PER_FRAME; }
  int startManager();
  int getFrame();

private:
  const int SCREEN_FPS;
  const int SCREEN_TICKS_PER_FRAME;
  Timer mTimer;
};

#endif // FRAME_RATE_COUNTER_HPP