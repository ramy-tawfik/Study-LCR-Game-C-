#include <iostream>
#include "read_Rulesfile.h"
#include"game.h"
using namespace std;

void test_dice(); //TODO remove after finish

int main() {
	game game;
	read_Rulesfile(); // display the game rule
	srand(time(NULL));  // "seed" Generate unique random numbers using the current time
	//test_dice();
	game.play();
	//ingame_test();
	cin.get();

	return 0;
}

//function to test the Dice class
void test_dice() {
	//test
	Dice d;
	for (auto i = 0; i < 10; i++)
	{
		for (int i = 0; i < 10; i++) {
			cout << d.rollDice() << "  ";
		}
		cout << "\n";
		//Sleep(1000);
	}
}
// function test ingame status