#ifndef TTT_MENU_H
#define TTT_MENU_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "main.h"

class Menu {
    int xScore;
    int oScore;
    bool isNewButtonHover;
    bool isExitButtonHover;
    SDL_Surface *newButtonHover;
    SDL_Surface *exitButtonHover;
  public:
    Menu();
    ~Menu();
    void clearScore();
    void handleEvents(SDL_Event event, int& gameStatus);
    void render(SDL_Surface *screen, int gameStatus);
};

#endif
