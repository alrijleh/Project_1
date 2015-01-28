/*
Container.cpp
This class holds a guess and its matching response

Fouad Al-Rijleh, Rachel Rudolph
*/
#include "Container.h"

//Empty Class Constructor
Container::Container()
{
	Code secretCode;
	Code guessCode;
	Response response;
}

Container::Container(Code newGuessCode, Response newResponse)
{
	Code guessCode;
	setGuessCode(newGuessCode);
	Response response;
	setResponse(newResponse);
}

//Default destructor
Container::~Container()
{
}

Code Container::getGuessCode() const
{
	return guessCode;
}

Response  Container::getResponse() const
{
	return response;
}

void  Container::setGuessCode(Code newGuessCode)
{
	guessCode = newGuessCode;
}

void  Container::setResponse(Response newResponse)
{
	response = newResponse;
}

//Overload output operator for Container class
ostream &operator<<(ostream &ostream, const Container container)
{
	ostream << "Guess Code:" << container.getGuessCode() << endl;
	ostream << "Response: " << container.getResponse() << endl;
	return ostream;
}