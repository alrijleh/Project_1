#pragma once

#include "Code.h"
#include "Response.h"
using namespace std;

class Container
{
private:
	Code secretCode;
	Code guessCode;
	Response response;
public:
	Container();
	~Container();

	Code getSecretCode() const;
	Code getGuessCode() const;
	Response getResponse() const;
	void setSecretCode(Code newSecretCode);
	void setGuessCode(Code newGuessCode);
	void setResponse(Response newResponse);
};
