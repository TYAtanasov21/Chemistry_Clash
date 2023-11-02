#pragma once

#include <iostream>
#include "raylib.h"

struct screenD {
    int screenWidth, screenHeight;
};

class game {
protected:
    const int screenWidth = 1600;
    const int screenHeight = 900;
public:

    screenD getScreenD();

};
