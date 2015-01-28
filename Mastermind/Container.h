/*
Container.h
This class holds a guess and its matching response

Fouad Al-Rijleh, Rachel Rudolph
*/

#pragma once

#include "Code.h"
#include "Response.h"
using namespace std;

class Container
{
private:
	Code guessCode;
	Response response;
public:
	Container();
	Container(Code newGuessCode, Response newResponse);
	~Container();

	Code getGuessCode() const;
	Response getResponse() const;
	void setGuessCode(Code newGuessCode);
	void setResponse(Response newResponse);

	friend ostream &operator<<(ostream &ostream, const Container container);
};
