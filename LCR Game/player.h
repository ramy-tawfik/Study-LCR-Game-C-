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
	int id = rand(); // to identify the player in case of two player with the same name
	int chips = 3; // player score

public:
	player(); // constructor
	~player();
	void setname(string& name1); // set the player name
	string getname() const; // get the player name
	void setschips(int s); // to change the number of chips for testing
	int getschips() const; // get player's chips count
	void addChip();  // add chip to playyer
	void subChip(); // subtract 1 chip from player's chips
	// operator overloading  to compare the player objects
	bool operator == (player& a);
};
