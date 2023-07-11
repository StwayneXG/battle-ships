# BattleShips Game

## Overview

This is a simple game of battleships. The game is played on a 10x10 grid. The player has 5 ships to place on the grid. The ships are of the following sizes: 2, 3, 3, 4, 5. The ships can be placed either horizontally or vertically on the grid. The ships cannot overlap or be placed outside the grid. The player can then take turns to fire at the grid and try to hit the ships. The game ends when all ships have been sunk.

## How to run

The game is written in C++. To run the game, you will need a C++ compiler. The game has been tested on Windows using g++.

To run the game, run the following command:

```
g++ -o battleships.exe Battleships.cpp Board.cpp
./battleships.exe
```

## How to play

The game will ask you to place your ships. You will be asked to enter the coordinates of the ship and enter 'U', 'D', 'L', 'R' to indicate the direction of the ship.

After placing your ships, you will be asked to enter the coordinates of the grid you want to fire at. The game will then tell you if you hit or missed. The game ends when all ships have been sunk.

## Future improvements

- Add a computer player
- Add a GUI
- Add a scoring system
- Add a leaderboard
- Add a menu
- Add a save/load feature

## License

This project is licensed under the MIT License - see the ```LICENSE``` file for details
