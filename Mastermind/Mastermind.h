/*
Mastermind.h
Handles the game mechanics

Fouad Al-Rijleh, Rachel Rudolph
*/

#include "Constants.h"
#include "Code.h"
#include "Response.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Mastermind
{
private:
	Code userCode;
	Code secretCode;
	Response response;
public:
	Mastermind();
	~Mastermind();

	void setUserCode(Code newUserCode);
	Code getUserCode() const;

	void setSecretCode(Code newSecretCode);
	Code getSecretCode() const;

	Code humanGuess();
	Response getResponse(Code userCode, Code secretCode) const;
	
	bool checkSolve(Response response) const;
	void playGame();

	void printCode() const;
};
