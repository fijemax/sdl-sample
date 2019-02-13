// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "core/core.hpp"
#include "util/SDLTestConfig.h"

using std::string;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stdout, "%s Version %d.%d\n",
                argv[0],
                SDLTest_VERSION_MAJOR,
                SDLTest_VERSION_MINOR);

        fprintf(stdout, "Usage: %s [ASSETS_PATH]\n", argv[0]);
        return 1;
    }
    string assetPaths(argv[1]);
    Core core(&assetPaths);
    return core.startGame();
}