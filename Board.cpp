#include "Board.h"

bool Board::placeShip(int x, int y, char direction,int size) {
    if (x > 10 || x < 1 || y>10 || y < 1 || (direction != 'U' && direction != 'D' && direction != 'L' && direction != 'R')) {
        return false;
    }
    else {
        switch (direction) {
        // U = Up, D = Down, L = Left, R = Right
        case 'U':
        {
            if (y + size > 10) {
                return false;
            }
            else {
                for (int i = 0; i < size; i++) {
                    if(mainBoard[x - 1][y - 1 + i].isShip)
                        return false;
                }
                for (int i = 0; i < size; i++) {
                    mainBoard[x - 1][y - 1 + i].isShip = true;
                }
            }
            break;
        }
        case 'D':
        {
            if (y - size < 1) {
                return false;
            }
            else {
                for (int i = 0; i < size; i++) {
                    if (mainBoard[x - 1][y - 1 - i].isShip)
                        return false;
                }
                for (int i = 0; i < size; i++) {
                    mainBoard[x - 1][y - 1 - i].isShip = true;
                }
            }

            break;
        }
        case 'L':
        {
            if (x + size > 10) {
                return false;
            }
            else {
                for (int i = 0; i < size; i++) {
                    if (mainBoard[x - 1 - i][y - 1].isShip)
                        return false;
                }
                for (int i = 0; i < size; i++) {
                    mainBoard[x - 1 - i][y - 1].isShip = true;
                }
            }
            break;
        }
        case 'R':
        {
            if (x - size < 1) {
                return false;
            }
            else {
                for (int i = 0; i < size; i++) {
                    if (mainBoard[x - 1 + i][y - 1].isShip)
                        return false;
                }
                for (int i = 0; i < size; i++) {
                    mainBoard[x - 1 + i][y - 1].isShip = true;
                }
            }
            break;
        }
        }
    }
    return true;
}

bool Board::attack(int x, int y) {
    if (x > 10 || x < 1 || y>10 || y < 1) {
        return false;
    }
    else {
        if (mainBoard[x - 1][y - 1].isDestroyed) {
            return false;
        }
        else {
            mainBoard[x - 1][y - 1].isDestroyed = true;
        }
        return true;
    }
}

bool Board::checkGameOver()
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (mainBoard[i][j].isShip && !mainBoard[i][j].isDestroyed) {
                return false;
            }
        }
    }
    return true;
}