#include "Container.h"

//Class Constructor
Container::Container()
{
}

//Default destructor
Container::~Container()
{
}


Code Container::getSecretCode() const
{
	return secretCode;
}

Code Container::getGuessCode() const
{
	return guessCode;
}

Response  Container::getResponse() const
{
	return response;
}

void  Container::setSecretCode(Code newSecretCode)
{
	secretCode = newSecretCode;
}

void  Container::setGuessCode(Code newGuessCode)
{
	guessCode = newGuessCode;
}

void  Container::setResponse(Response newResponse)
{
	response = newResponse;
}