#include "menu.h"

Menu::Menu()
{
    clearScore();
    isNewButtonHover = false;
    isExitButtonHover = false;
    newButtonHover = loadImage("img/new_button_hover.png");
    exitButtonHover = loadImage("img/exit_button_hover.png");
}

Menu::~Menu()
{
    SDL_FreeSurface(newButtonHover);
    SDL_FreeSurface(exitButtonHover);
}

void Menu::clearScore()
{
    xScore = 0;
    oScore = 0;
}

void Menu::handleEvents(SDL_Event event, int& gameStatus)
{
    int x, y;
    if (event.type == SDL_MOUSEMOTION) {
        x = event.motion.x;
        y = event.motion.y;
        if ((x > 350) && (y > 220) && (y < 285)) {
            isNewButtonHover = true;
        } else {
            isNewButtonHover = false;
        }
        if ((x > 350) && (y > 285)) {
            isExitButtonHover = true;
        } else {
            isExitButtonHover = false;
        }
    }

    if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT)) {
        if (isExitButtonHover) {
            gameStatus = END;
        } else if (isNewButtonHover) {
            gameStatus = NEW_GAME;
            clearScore();
        }
    }
}

void Menu::render(SDL_Surface *screen, int gameStatus)
{
    if (isNewButtonHover) {
        applySurface(412, 246, newButtonHover, screen);
    } else if (isExitButtonHover) {
        applySurface(414, 294, exitButtonHover, screen);
    }
}
