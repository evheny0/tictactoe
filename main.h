#ifndef TTT_MAIN_H
#define TTT_MAIN_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <string>

#include "field.h"
#include "graphics.h"

enum currPlayer_t {
    X_PLAYER,
    O_PLAYER
};

bool mainLoop(SDL_Surface *screen);

#endif
