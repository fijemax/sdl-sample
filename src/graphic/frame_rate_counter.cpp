#include "graphic/frame_rate_counter.hpp"

#include "util/timer.hpp"

int FrameRateCounter::startManager()
{
    mTimer.start();
    return 0;
}

int FrameRateCounter::getFrame()
{
    return mTimer.getTicks();
}
