#include "field.h"

Field::Field()
{
    cleanValues();
    hoverCoords.x = -1;
    hoverCoords.y = -1;
    backgroundImg = loadImage("img/bg.png");
    xHoverImg = loadImage("img/x_hover.png");
    oHoverImg = loadImage("img/o_hover.png");
    xImg = loadImage("img/x.png");
    oImg = loadImage("img/o.png");
    xWinImg = loadImage("img/x_win.png");
    oWinImg = loadImage("img/o_win.png");
    drawImg = loadImage("img/draw.png");

    if (!backgroundImg || !xHoverImg || !oHoverImg || !xImg || !oImg || !xWinImg || !oWinImg || !drawImg) {
        std::cerr << "Can't load files\n";
        exit(1);
    }
}

Field::~Field()
{
    SDL_FreeSurface(backgroundImg);
    SDL_FreeSurface(xHoverImg);
    SDL_FreeSurface(oHoverImg);
    SDL_FreeSurface(xImg);
    SDL_FreeSurface(oImg);
    SDL_FreeSurface(xWinImg);
    SDL_FreeSurface(oWinImg);
    SDL_FreeSurface(drawImg);
}

void Field::cleanValues()
{
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            values[i][j] = EMPTY_CELL;
        }
    }
}

void Field::handleEvents(SDL_Event event, int& gameStatus)
{
    if (gameStatus == END) {
        return;
    }

    int x, y;

    if (event.type == SDL_MOUSEBUTTONDOWN) {
        x = (event.button.x - 15) / 110;
        y = (event.button.y - 15) / 110;
        if ((event.button.button == SDL_BUTTON_LEFT) && (x < 3) && (y < 3)) {
            switch (gameStatus) {
            case X_PLAYER_WIN:
                cleanValues();
                gameStatus = O_PLAYER;
                return;
            case O_PLAYER_WIN:
                cleanValues();
                gameStatus = X_PLAYER;
                return;
            case DRAW:
                cleanValues();
                gameStatus = rand() % 2;
                return;
            }

            if (values[y][x] == EMPTY_CELL) {
                if (gameStatus == X_PLAYER) {
                    values[y][x] = X_CELL;
                    gameStatus = O_PLAYER;
                    hoverCoords.x = -1;
                    hoverCoords.y = -1;
                } else {
                    values[y][x] = O_CELL;
                    gameStatus = X_PLAYER;
                    hoverCoords.x = -1;
                    hoverCoords.y = -1;
                }
            }
        }
    }

    if (event.type == SDL_MOUSEMOTION) {
        x = (event.motion.x - 15) / 110;
        y = (event.motion.y - 15) / 110;
        if ((x < 3) && (y < 3)) {
            switch (values[y][x]) {
            case X_CELL:
                hoverCoords.x = -1;
                hoverCoords.y = -1;
                break;
            case O_CELL:
                hoverCoords.x = -1;
                hoverCoords.y = -1;
                break;
            case EMPTY_CELL:
                hoverCoords.x = x;
                hoverCoords.y = y;
                break;
            }
        } else {
            hoverCoords.x = -1;
            hoverCoords.y = -1;
        }
    }

}

void Field::checkGameStatus(int& gameStatus)
{
    if (gameStatus == END) {
        return;
    }
    if (gameStatus == NEW_GAME) {
        gameStatus == X_PLAYER;
        cleanValues();
    }

    int i, j;
    bool isEmptyCells = 0;
    
    if (((values[0][0] == values[1][1]) && (values[0][0] == values[2][2]) && (values[0][0] != EMPTY_CELL)) ||
        ((values[0][2] == values[1][1]) && (values[0][2] == values[2][0]) && (values[0][2] != EMPTY_CELL))) {
        if (values[1][1] == X_CELL) {
            gameStatus = X_PLAYER_WIN;
            return;
        } else {
            gameStatus = O_PLAYER_WIN;
            return;
        }
    }
    for (i = 0; i < 3; i++) {
        if (((values[i][0] == values[i][1]) && (values[i][0] == values[i][2]) && (values[i][0] != EMPTY_CELL)) ||
            ((values[0][i] == values[1][i]) && (values[0][i] == values[2][i]) && (values[0][i] != EMPTY_CELL))) {
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
    applySurface(0, 0, backgroundImg, screen);

    if (hoverCoords.x != -1) {
        if (gameStatus == X_PLAYER) {
            applySurface(15 + (hoverCoords.x * 110), 15 + (hoverCoords.y * 110), xHoverImg, screen);
        } else if (gameStatus == O_PLAYER) {
            applySurface(15 + (hoverCoords.x * 110), 15 + (hoverCoords.y * 110), oHoverImg, screen);
        }
        
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            switch (values[i][j]) {
            case X_CELL:
                applySurface(15 + (j * 110), 15 + (i * 110), xImg, screen);
                break;
            case O_CELL:
                applySurface(15 + (j * 110), 15 + (i * 110), oImg, screen);
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
