#pragma once
#include<ctime>
#include<iostream>
class Dice
{
private:
	int face;

public:
	Dice();
	~Dice();
	int rollDice();// roll the dice and return the face value
};
