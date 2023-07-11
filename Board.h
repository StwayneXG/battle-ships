#pragma once

struct Box {
	bool isShip = false;
	bool isDestroyed = false;
};

class Board {
private:
    Box mainBoard[10][10];
public:
	bool placeShip(int x, int y, char direction,int size);
    bool attack(int x, int y);
	bool checkGameOver();
};