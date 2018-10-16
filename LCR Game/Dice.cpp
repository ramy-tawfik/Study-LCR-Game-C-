#include "Dice.h"

Dice::Dice()
{
}

Dice::~Dice()
{
}

int Dice::rollDice()
{
	// Get a random number between 1 and 6
	Dice::face = (rand() % 6) + 1; // Added 1 to make the number from 1 to 6 not from 0 to 5
	return Dice::face; // return the dice face
}