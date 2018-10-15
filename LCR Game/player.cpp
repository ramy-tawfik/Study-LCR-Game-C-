#include"player.h"

using namespace std;

// function to set the value of name
void player::setname(string& name1) {
	name = name1;
}
//return the player name
string player::getname()const {
	return name;
}
// function to set the value of score
void player::setschips(int s) {
	chips = s;
}
//return the player score
int player::getschips() const {
	return chips;
}

void player::addChip()
{
	chips += 1;
}

void player::subChip()
{
	chips -= 1;
}

bool player::operator==(player & a)
{
	if (this->getname() == a.getname() && this->getschips() == a.getschips() && this->id == a.id)
	{
		return true;
	}
	else {
		return false;
	}
}

player::player()
{
}

player::~player()
{
}