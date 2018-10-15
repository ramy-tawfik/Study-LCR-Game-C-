#pragma once
// the header file for the player class contain declerations

#include<iostream>
#include<string>

using namespace std;
// player class
class player
{
private:
	string name; // player name
	int id = rand();// to identify the player case of two player with the same name
	int chips = 3; // player score

public:
	player();
	~player();
	void setname(string& name1);
	string getname() const;
	void setschips(int s);
	int getschips() const;
	void addChip();
	void subChip();
	bool operator == (player& a);
};
