#include "main.h"

//анимация рисования
int main(int argc, char *argv[])
{
    SDL_Surface *screen;
    screen = screenInit();
    if (!screen) {
        std::cerr << "Initialization failed.";
        return 1;
    }

    return mainLoop(screen);
}

bool mainLoop(SDL_Surface *screen)
{
    bool isEnd = false;
    bool player = X_PLAYER;
    Field field;

    SDL_Event event;
    /*
    SDL_Surface *fieldImg = loadImage("img/field.png");
    SDL_Surface *xImg = loadImage("img/x.png");
    SDL_Surface *oImg = loadImage("img/o.png");
    if (!fieldImg || !xImg || !oImg) {
        return 1;
    }*/
    while (!isEnd) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isEnd = 1;
            }
            field.handleEvents(event, player);
        }

        field.render(screen);

        if (SDL_Flip(screen) == -1) {
            return 1;
        }
    }
}
