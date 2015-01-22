/*
Project 1a
Main.cpp
Initializes the mastermind object and calls playGame()

Fouad Al-Rijleh, Rachel Rudolph
*/

#include "Main.h"


ostream &operator<<(ostream &ostream, const Code &code)
{
	for (int index = 0; index < code.code.size(); index++)
	{
		ostream << code.code[index];
	}
	return ostream;
}

//Main
void main()
{
	Mastermind masterMind;
	masterMind.playGame();
	system("pause");
}
