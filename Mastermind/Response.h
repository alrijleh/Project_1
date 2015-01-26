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

	int getNumCorrect() const;
	int getNumIncorrect() const;
	
	bool isEqual(Response externalResponse);

	void printResponse();

	friend ostream &operator<<(ostream &ostr, const Response &response);
	friend bool operator==(const Response &response, const Response &newResponse);
	Response &Response::operator=(const Response &response);

};
