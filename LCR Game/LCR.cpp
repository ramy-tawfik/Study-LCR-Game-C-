/*
Ramy Tawfik
10/17/2018
Ramy.Tawfik@snhu.edu
*/

#include <iostream>
#include "read_Rulesfile.h"
#include"game.h"
using namespace std;

int main() {
	game game;
	read_Rulesfile(); // display the game rule
	srand(time(NULL));  // "seed" Generate unique random numbers using the current time
	game.play(); // call the play function

	cin.get();
	return 0;
}

//function to test the Dice class
/*void test_dice() {
	Dice d;
	for (auto i = 0; i < 10; i++)
	{
		for (int i = 0; i < 10; i++) {
			cout << d.rollDice() << "  ";
		}
		cout << "\n";
	}
}*/