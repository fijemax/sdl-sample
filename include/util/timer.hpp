#ifndef TIME_HPP
#define TIME_HPP

#include <stdint.h>
class Timer
{
  public:
    Timer() : mStartTicks(0), mPausedTicks(0), mPaused(false), mStarted(false) {}

    void start();
    void stop();
    void pause();
    void unpause();

    uint32_t getTicks();

    bool isStarted()
    {
        return mStarted;
    }

    bool isPaused()
    {
        return mPaused && mStarted;
    }

  private:
    uint32_t mStartTicks;
    uint32_t mPausedTicks;
    bool mPaused;
    bool mStarted;
};

#endif // TIME_HPP