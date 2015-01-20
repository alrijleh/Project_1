/*
Response.h
Stores the response to a user guess

Fouad Al-Rijleh, Rachel Rudolph
*/

#pragma once

#include "Constants.h"
#include <iostream>

using namespace std;

class Response
{
private:
	int numCorrect;
	int numIncorrect;

public:
	Response();
	~Response();

	void setNumCorrect(int newNumCorrect);
	void setNumIncorrect(int newNumIncorrect);

	int getNumCorrect();
	int getNumIncorrect();
	
	bool checkSolve();
	bool areEqual();

	void printResponse();
};
