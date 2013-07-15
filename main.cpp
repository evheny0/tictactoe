#include "main.h"

int main(int argc, char *argv[])
{
    SDL_Surface *screen;
    screen = screenInit();
    if (!screen) {
        return 1;
    }

    if (mainLoop(screen)) {
        return 1;
    }

    SDL_Quit();
    return 0;
}

bool mainLoop(SDL_Surface *screen)
{
    int gameStatus = X_PLAYER;
    Field field;
    Menu menu;
    SDL_Event event;

    while (gameStatus != END) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                gameStatus = END;
            }
            field.handleEvents(event, gameStatus);
            menu.handleEvents(event, gameStatus);
        }

        field.checkGameStatus(gameStatus);
        menu.checkScore(gameStatus);

        field.render(screen, gameStatus);
        menu.render(screen, gameStatus);

        if (SDL_Flip(screen) == -1) {
            return 1;
        }
    }
    return 0;
}
