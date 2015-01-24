/*
Project 1a
Main.cpp
Initializes the mastermind object and calls playGame()

Fouad Al-Rijleh, Rachel Rudolph
*/

#include "Main.h"

//Overload output operator
ostream &operator<<(ostream &ostream, const Response &newResponse){
	ostream << "(" << newResponse.getNumCorrect() << ", " << newResponse.getNumIncorrect() << ")";
	
	return ostream;
}

//Overload assign operator
bool operator==(const Response &response, const Response &newResponse){
	return newResponse.getNumCorrect() == response.getNumCorrect() 
		&& newResponse.getNumIncorrect() == response.getNumIncorrect();

}

Response &Response::operator=(const Response &response){
	numCorrect = response.getNumCorrect();
	numIncorrect = response.getNumIncorrect();
	return *this;
}



//Main
void main()
{
	Mastermind masterMind;
	masterMind.playGame();
	system("pause");
}

