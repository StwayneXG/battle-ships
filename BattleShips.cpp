#include <iostream>
#include "Board.h"

using std::cin;
using std::cout;
using std::endl;

const int shipSizeArr[] = { 2,2,3,4,5 };

void playGame()
{
	Board player1;
	Board player2;
	cout << "Player 1:\nPlace Ships:\n";
	for (int i = 0; i < 5; i++)
	{
	TryAgain1:
		int x; int y; char direction;
		cout << "For Ship sized: " << shipSizeArr[i] << endl;
		cout << "Enter x-coordinate: ";
		cin >> x;
		cout << "Enter y-coordinate: ";
		cin >> y;
		cout << "Enter direction(U,D,L,R): ";
		cin >> direction;
		if (!player1.placeShip(x, y, direction, shipSizeArr[i]))
		{
			cout << "Invalid Entry. Try again.\n";
			goto TryAgain1;
		}
	}
	system("cls");
	cout << "Player 2:\nPlace Ships:\n";
	for (int i = 0; i < 5; i++)
	{
	TryAgain2:
		int x; int y; char direction;
		cout << "For Ship sized: " << shipSizeArr[i] << endl;
		cout << "Enter x-coordinate: ";
		cin >> x;
		cout << "Enter y-coordinate: ";
		cin >> y;
		cout << "Enter direction(U,D,L,R): ";
		cin >> direction;
		if (!player2.placeShip(x, y, direction, shipSizeArr[i]))
		{
			cout << "Invalid Entry. Try again.\n";
			goto TryAgain2;
		}
	}
	system("cls");
	while (true)
	{
	AttackTryAgain1:
		cout << "Player 1 Attack:\n";
		int x; int y;
		cout << "Enter x-coordinate: ";
		cin >> x;
		cout << "Enter y-coordinate: ";
		cin >> y;

		if (!player2.attack(x, y))
		{
			cout << "Invalid Attack. Try again.\n";
			goto AttackTryAgain1;
		}
		if (player2.checkGameOver())
		{
			system("cls");
			cout << "Player 1 Wins." << endl;
			break;
		}
		system("cls");
	AttackTryAgain2:
		cout << "Player 2 Attack:\n";

		cout << "Enter x-coordinate: ";
		cin >> x;
		cout << "Enter y-coordinate: ";
		cin >> y;
		if (!player1.attack(x, y))
		{
			cout << "Invalid Attack. Try again.\n";
			goto AttackTryAgain2;
		}
		if (player1.checkGameOver())
		{
			system("cls");
			cout << "Player 2 Wins." << endl;
			break;
		}
		system("cls");
	}
}

int main()
{
	playGame();
}
