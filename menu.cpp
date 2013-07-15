#include "menu.h"

Menu::Menu()
{
    clearScore();
    isScoreChecked = false;
    isNewButtonHover = false;
    isExitButtonHover = false;
    textColor = {66, 58, 56};
    font = TTF_OpenFont("font/FreeSansBold.ttf", 46);
    newButtonHover = loadImage("img/new_button_hover.png");
    exitButtonHover = loadImage("img/exit_button_hover.png");

    if (!font || !newButtonHover || !exitButtonHover) {
        std::cerr << "Can't load files\n";
        exit(1);
    }
}

Menu::~Menu()
{
    TTF_CloseFont(font);
    SDL_FreeSurface(newButtonHover);
    SDL_FreeSurface(exitButtonHover);
}

void Menu::clearScore()
{
    xScore = 0;
    oScore = 0;
    sprintf(xScoreString, "%d", xScore);
    sprintf(oScoreString, "%d", oScore);
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

void Menu::checkScore(int gameStatus)
{
    if (!isScoreChecked) {
        if (gameStatus == X_PLAYER_WIN) {
            isScoreChecked = true;
            xScore += 1;
            sprintf(xScoreString, "%d", xScore);
        }
        if (gameStatus == O_PLAYER_WIN) {
            isScoreChecked = true;
            oScore += 1;
            sprintf(oScoreString, "%d", oScore);
        }
    } else {
        if ((gameStatus == O_PLAYER) || (gameStatus == X_PLAYER)) {
            isScoreChecked = false;
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

    scoreSurface = TTF_RenderText_Solid(font, xScoreString, textColor);
    applySurface(475, 40, scoreSurface, screen);
    SDL_FreeSurface(scoreSurface);  
    scoreSurface = TTF_RenderText_Solid(font, oScoreString, textColor);
    applySurface(475, 150, scoreSurface, screen);  
    SDL_FreeSurface(scoreSurface);  
}
