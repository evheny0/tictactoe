#ifndef TTT_FIELD_H
#define TTT_FIELD_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include "main.h"

enum FieldCell { 
    EMPTY_CELL,
    X_CELL,
    O_CELL
};

class Field
{
	int values[3][3];
    SDL_Surface *backgroundImg;
    SDL_Surface *xHoverImg;
    SDL_Surface *oHoverImg;
    SDL_Surface *xImg;
    SDL_Surface *oImg;
    SDL_Surface *xWinImg;
    SDL_Surface *oWinImg;
    SDL_Surface *drawImg;
    SDL_Rect hoverCoords;
  public:
	Field();
    ~Field();
	bool setValue(int x, int y, int value);
    void cleanValues();
    void handleEvents(SDL_Event event, int& gameStatus);
    void checkGameStatus(int& gameStatus);
    void render(SDL_Surface *screen, int gameStatus);
};

#endif
