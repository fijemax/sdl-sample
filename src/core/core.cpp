#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "core/core.hpp"
#include "SDL.h"
#include "SDL_image.h"

using std::string;

int Core::startGame()
{
    int res = mWindowManager.init();
    if (res != 0)
    {
        return -1;
    }
    mIsStart = true;
    return mWindowManager.display();
}