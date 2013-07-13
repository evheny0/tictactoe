#include "field.h"

Field::Field()
{
    cleanValues();
    fieldImg = loadImage("img/field.png");
    xImg = loadImage("img/x.png");
    oImg = loadImage("img/o.png");
    xWinImg = loadImage("img/x_win.png");
    oWinImg = loadImage("img/o_win.png");
    drawImg = loadImage("img/draw.png");
}

Field::~Field()
{
    SDL_FreeSurface(fieldImg);
    SDL_FreeSurface(xImg);
    SDL_FreeSurface(oImg);
    SDL_FreeSurface(xWinImg);
    SDL_FreeSurface(oWinImg);
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

void Field::cleanValues()
{
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            values[i][j] = 0;
        }
    }
}

void Field::handleEvents(SDL_Event event, int& gameStatus)
{
    if ((gameStatus == X_PLAYER_WIN) || (gameStatus == O_PLAYER_WIN) || (gameStatus == END)) {
        return;
    }
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
                if (gameStatus == X_PLAYER) {
                    values[y][x] = X_CELL;
                    gameStatus = O_PLAYER;
                } else {
                    values[y][x] = O_CELL;
                    gameStatus = X_PLAYER;
                }
                break;
            }
        }
    }
}

void Field::checkVictory(int& gameStatus)
{
    if (gameStatus == END) {
        return;
    }
    int i, j;
    bool isEmptyCells = 0;
    for (i = 0; i < 3; i++) {
        if (((values[i][0] == values[i][1]) && (values[i][0] == values[i][2]) && (values[i][0] != EMPTY_CELL)) ||
            ((values[0][i] == values[1][i]) && (values[0][i] == values[2][i]) && (values[0][i] != EMPTY_CELL)) ||
            ((values[0][0] == values[1][1]) && (values[0][0] == values[2][2]) && (values[0][0] != EMPTY_CELL)) ||
            ((values[0][2] == values[1][1]) && (values[0][2] == values[2][0]) && (values[0][2] != EMPTY_CELL))) {
            if (values[i][i] == X_CELL) {
                gameStatus = X_PLAYER_WIN;
                return;
            } else {
                gameStatus = O_PLAYER_WIN;
                return;
            }
        }

        for (j = 0; j < 3; j++) {
            if (values[i][j] == EMPTY_CELL) {
                isEmptyCells = 1;
            }
        }
    }

    if (isEmptyCells == 0) {
        gameStatus = DRAW;
    }
}

void Field::render(SDL_Surface *screen, int gameStatus)
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
    switch (gameStatus) {
    case X_PLAYER_WIN:
        applySurface(70, 135, xWinImg, screen);
        break;
    case O_PLAYER_WIN:
        applySurface(70, 135, oWinImg, screen);
        break;
    case DRAW:
        applySurface(70, 135, drawImg, screen);
        break;
    }
}
