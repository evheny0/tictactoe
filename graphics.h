#ifndef TTT_GRAPHICS_H
#define TTT_GRAPHICS_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <string>

const int SCREEN_WIDTH = 575;
const int SCREEN_HEIGHT = 350;
const int SCREEN_BPP = 32;

SDL_Surface *screenInit();
SDL_Surface *loadImage(std::string filename);
void applySurface(int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip = NULL);

#endif
