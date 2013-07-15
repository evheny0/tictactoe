#ifndef TTT_MAIN_H
#define TTT_MAIN_H

#include <SDL/SDL.h>

#include "field.h"
#include "graphics.h"
#include "menu.h"

enum GameStatus {  
    X_PLAYER,
    O_PLAYER,
    X_PLAYER_WIN,
    O_PLAYER_WIN,
    DRAW,
    END,
    NEW_GAME
};

bool mainLoop(SDL_Surface *screen);

#endif
