#include "field.h"

Field::Field()
{
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            values[i][j] = 0;
        }
    }
    fieldImg = loadImage("img/field.png");
    xImg = loadImage("img/x.png");
    oImg = loadImage("img/o.png");
}

bool Field::setValue(int x, int y, int value)
{
    //need values for warnings
    if ((value != EMPTY_CELL) && (values[y][x] != EMPTY_CELL)) {
        return false;
    } else {
        values[y][x] = value;
        return true;
    }
}

int Field::checkValue(int x, int y)
{
    return values[y][x];
}

void Field::handleEvents(SDL_Event event, bool& player)
{
    int x, y;
    x = (event.button.x - 10) / 110;
    y = (event.button.y - 10) / 110;
    if (x > 3 || x < 0 || y > 3 || x < 0) {
        return;
    }

    if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (event.button.button == SDL_BUTTON_LEFT) {
            switch (values[y][x]) {
            case X_CELL:
                break;
            case O_CELL:
                break;
            case EMPTY_CELL:
                if (player == X_PLAYER) {
                    values[y][x] = X_CELL;
                    player = !player;
                } else {
                    values[y][x] = O_CELL;
                    player = !player;
                }
                break;
            }
        }
    }
}

void Field::render(SDL_Surface *screen)
{
    int i, j;
    applySurface(0, 0, fieldImg, screen);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            switch (values[i][j]) {
            case X_CELL:
                applySurface(10 + (j * 110), 10 + (i * 110), xImg, screen);
                break;
            case O_CELL:
                applySurface(10 + (j * 110), 10 + (i * 110), oImg, screen);
                break;
            }
        }
    }
}
