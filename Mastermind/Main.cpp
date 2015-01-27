/*
Project 1a
Main.cpp
Initializes the mastermind object and calls playGame()

Fouad Al-Rijleh, Rachel Rudolph
*/

#include "Main.h"

//Main
void main()
{
	try
	{
		Mastermind masterMind;
		masterMind.playGame2();
	}
	catch (rangeError &ex)
	{
		cerr << "rangeError: " << ex.what() << endl;
	}
	system("pause");
}

