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
	else
	{
		cerr << "Input must be integer less than LENGTH.";
		throw "input error";
	}
}

//Sets the number incorrect
void Response::setNumIncorrect(int newNumIncorrect)
{
	if (newNumIncorrect <= LENGTH && newNumIncorrect >= 0){
		numIncorrect = newNumIncorrect;
	}
	else
	{
		cerr << "Input must be integer less than LENGTH.";
		throw "input error";
	}
}

//Gets the number correct
int Response::getNumCorrect() const
{
	return numCorrect;
}

//Gets the number incorrect
int Response::getNumIncorrect() const
{
	return numIncorrect;
}

//Check if number correct is equal to number incorrect
bool Response::isEqual(Response externalResponse)
{
	if (externalResponse.getNumCorrect() == numCorrect && externalResponse.getNumIncorrect() == numIncorrect) return true;
	else return false;
}

//Prints response in format (correct, incorrect)
void Response::printResponse()
{
	cout << "Response: (" << numCorrect << ", " << numIncorrect << ")" << endl;
}
