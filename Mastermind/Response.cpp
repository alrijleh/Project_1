/*
Response.cpp
Stores the response to a user guess

Fouad Al-Rijleh, Rachel Rudolph
*/

#include "Response.h"

//Constructor that sets the values to 0
Response::Response()
{
	Response::setNumCorrect(0);
	Response::setNumIncorrect(0);
}

//Default destructor
Response::~Response()
{
}

//Sets the number correct
void Response::setNumCorrect(int newNumCorrect)
{
	if (newNumCorrect <= LENGTH && newNumCorrect >= 0){
		numCorrect = newNumCorrect;
	}
	else cout << "Input must be integer less than LENGTH.";
}

//Sets the number incorrect
void Response::setNumIncorrect(int newNumIncorrect)
{
	if (newNumIncorrect <= LENGTH && newNumIncorrect >= 0){
		numIncorrect = newNumIncorrect;
	}
	else cout << "Input must be integer less than LENGTH.";
}

//Gets the number correct
int Response::getNumCorrect()
{
	return numCorrect;
}

//Gets the number incorrect
int Response::getNumIncorrect()
{
	return numIncorrect;
}

//Check if guess is correct
bool Response::checkSolve()
{
	if (numCorrect == LENGTH) return true;
	else return false;
}

//Check if number correct is equal to number incorrect
bool Response::areEqual()
{
	if (numCorrect == numIncorrect) return true;
}

//Prints response
void Response::printResponse()
{
	cout << "Response: (" << numCorrect << ", " << numIncorrect << ")" << endl;
}