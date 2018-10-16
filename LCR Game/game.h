#pragma once
#include "player.h"
#include "Dice.h"
#include <vector>

class game
{
private:
	Dice dice; // an instance of the Dice class
	vector <player> pv; // vector to save the player objects
	int numplayer = 0;
	int center = 0; // center bucket
	// get player information
	void getPlayerInfo();
	// move 1 chip to the left player
	void moveToLeft(player& p);
	// move 1 chip to the righ
	void moveToRight(player& p);
	// move 1 chip to the center
	void moveToCenter(player& p);
	// chech if game is ended
	bool gameover(vector<player>& v);
	// display players states
	void printStates();
	// print a line on the screen
	void printLine();

public:
	game();
	~game();
	// main function to start playing
	void play();
};
