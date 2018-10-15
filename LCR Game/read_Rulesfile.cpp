#include "read_Rulesfile.h"

using namespace std;

void read_Rulesfile() {
	cout << "Welcome to the LCR Dice Game\n\n";
	cout << "Game Rules\n\n";
	ifstream myReadFile;  // creating ifstream objest
	myReadFile.open("rules.txt"); // open the text file
	string output;
	if (myReadFile.is_open()) {
		// while not the end of the file
		while (!myReadFile.eof()) {
			getline(myReadFile, output); // read line by line and save it in output string
			cout << output << endl;// print out the line of text
		}
	}
	//in case that we failed to open the file
	else
	{
		cout << "no file found" << endl;
	}
	myReadFile.close();// close the file stream
	cout << "PRESS ENTER TO START....\n\n";
	cin.get();
	system("cls"); // Clear the console with the "system" function
}