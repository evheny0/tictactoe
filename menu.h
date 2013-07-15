#ifndef TTT_MENU_H
#define TTT_MENU_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "main.h"

class Menu {
    int xScore;
    int oScore;
    char xScoreString[8];
    char oScoreString[8];
    bool isScoreChecked;
    bool isNewButtonHover;
    bool isExitButtonHover;
    TTF_Font *font;
    SDL_Color textColor;
    SDL_Surface *scoreSurface;
    SDL_Surface *newButtonHover;
    SDL_Surface *exitButtonHover;
  public:
    Menu();
    ~Menu();
    void clearScore();
    void handleEvents(SDL_Event event, int& gameStatus);
    void checkScore(int gameStatus);
    void render(SDL_Surface *screen, int gameStatus);
};

#endif
