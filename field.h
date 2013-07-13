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
    SDL_Surface *xWinImg;
    SDL_Surface *oWinImg;
  public:
	Field();
    ~Field();
	bool setValue(int x, int y, int value);
    void cleanValues();
    void handleEvents(SDL_Event event, int& gameStatus);
    void checkVictory(int& gameStatus);
    void render(SDL_Surface *screen, int gameStatus);
};

#endif
