#pragma once
#include "player.h"
#include "Dice.h"
#include <vector>

class game
{
private:
	Dice dice;
	vector <player> pv;
	int numplayer = 0;
	int center = 0;
	void getPlayerInfo();
	void moveToLeft(player& p);
	void moveToRight(player& p);
	void moveToCenter(player& p);
	bool gameover(vector<player>& v);
	void printStates();

public:
	game();
	~game();
	void play();
};
