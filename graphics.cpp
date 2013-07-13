#include "graphics.h"

SDL_Surface *screenInit()
{
    SDL_Surface *screen;

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        std::cerr << "Initialization failed.";
        return NULL;
    }

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    SDL_WM_SetCaption("Tic Tac Toe", NULL);
    SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
    
    return screen;
}

SDL_Surface *loadImage(std::string filename)
{
    SDL_Surface *loadedImage;
    SDL_Surface *optimizedImage;

    loadedImage = IMG_Load(filename.c_str());
    optimizedImage = SDL_DisplayFormat(loadedImage);
    SDL_FreeSurface(loadedImage);
    SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB(optimizedImage->format, 0xFF, 0, 0xFF));

    return optimizedImage;
}

void applySurface(int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip)
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(source, clip, destination, &offset);
} 
