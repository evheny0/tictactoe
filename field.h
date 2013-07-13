#ifndef TTT_FIELD_H
#define TTT_FIELD_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include "main.h"

#define EMPTY_CELL 0
#define X_CELL 1
#define O_CELL 2

class Field
{
	int values[3][3];
    SDL_Surface *fieldImg;
    SDL_Surface *xImg;
    SDL_Surface *oImg;
  public:
	Field();
	bool setValue(int x, int y, int value);
    int checkValue(int x, int y);
    void handleEvents(SDL_Event event, bool& player);
    void render(SDL_Surface *screen);
};

#endif
