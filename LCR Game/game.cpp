#include "game.h"

using namespace std;

game::game()
{
}

game::~game()
{
}

//function to take the number of the players and there name
// and add players the players vector
void game::getPlayerInfo()
{
	while (numplayer < 3)
	{
		cout << "\nPlease enter the number of Players : ";
		cin >> numplayer;
		if (numplayer < 3)
		{
			cout << "\nMinimum number of Players is Three ";
		}
	}

	string tempname; //temporarly hold the name
	for (int i = 0; i < numplayer; i++)
	{
		player p;
		cout << "\nplease enter player number " << i + 1 << " name ";
		cin >> tempname;
		p.setname(tempname); // set the name of the player to the player object
		pv.push_back(p); // add it to the vector
	}
}

void game::play()
{
	getPlayerInfo();
	cout << "\nBeging of the LCR Dice game.\n\n";
	printStates();

	int dice_face;

	int tempchips;
	while (!gameover(pv))
	{
		for (int i = 0; i < numplayer; i++) {
			tempchips = pv[i].getschips();
			if (tempchips > 3)
			{
				tempchips = 3;
			}
			for (int y = 1; y <= tempchips; y++)
			{
				dice_face = dice.rollDice();
				switch (dice_face)
				{
				case 1: //left
					cout << " \n" << pv[i].getname() << " Dice number " << y << " is L\nSCORE :\n";
					moveToLeft(pv[i]);
					break;
				case 2: //right
					cout << " \n" << pv[i].getname() << " Dice number " << y << " is R\nSCORE :\n";
					moveToRight(pv[i]);
					break;
				case 3: // center
					cout << " \n" << pv[i].getname() << " Dice number " << y << " is C\nSCORE :\n";
					moveToCenter(pv[i]);
					break;
				default: // Dots
					cout << " \n" << pv[i].getname() << " Dice number " << y << " is *\nSCORE :\n";
					break;
				}
				printStates();
			}
			//cout << "\n" << a.getname() << " " << a.getschips();
		}
	}

	/*for (auto a : pv) {
		cout << "\n" << a.getname() << " " << a.getschips();
	}*/

	cin.get();
}

void game::moveToRight(player & p)
{
	if (pv[0] == p) // First player
	{
		p.subChip();
		pv[numplayer - 1].addChip();//give to last player
		cout << " 1 chip moved from " << p.getname() << " to " << pv[numplayer - 1].getname() << "\n";
	}
	else
	{
		for (int i = 0; i < numplayer; i++)
		{
			if (pv[i] == p)
			{
				pv[i].subChip();
				pv[i - 1].addChip();
				cout << " 1 chip moved from " << pv[i].getname() << " to " << pv[i - 1].getname() << "\n";
			}
		}
	}
}

void game::moveToLeft(player & p)
{
	if (pv[numplayer - 1] == p) // last player
	{
		p.subChip();
		pv[0].addChip();
		cout << " 1 chip moved from " << p.getname() << " to " << pv[0].getname() << "\n";
	}
	else
	{
		for (int i = 0; i < numplayer; i++)
		{
			if (pv[i] == p)
			{
				pv[i + 1].addChip();
				pv[i].subChip();
				cout << " 1 chip moved from " << pv[i].getname() << " to " << pv[i + 1].getname() << "\n";
			}
		}
	}
}

void game::moveToCenter(player & p)
{
	cout << " 1 chip moved to the Center from " << p.getname() << "\n";
	p.subChip();
	center += 1;
}

bool game::gameover(vector<player>& v)
{
	int playerWithChips = 0;

	for (auto a : v) {
		if (a.getschips() > 0) // check how many player has chips
		{
			playerWithChips += 1;
		}
	}
	if (playerWithChips == 1) //only one player has chips
	{
		for (auto a : v) {
			if (a.getschips() > 0)
			{
				cout << "\nGame Over The winner is " << a.getname()
					<< " with " << a.getschips() << " Chips.\n\n";

				cout << "Final Game Scores\n";
				printStates();

				return true;
			}
		}
	}
	else
	{
		return false;
	}
}

void game::printStates()
{
	for (auto a : pv)
	{
		cout << "\nPlayer " << a.getname() << " Has " << a.getschips() << " Chips\n";
	}
	cout << "\nThe Center Bucket Contains " << center << " Chip\\s\n\n";
}