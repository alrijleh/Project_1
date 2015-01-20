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
public:
	Mastermind();
	~Mastermind();

	Code humanGuess();
	Response getResponse(Code userCode, Code secretCode);
	void playGame();

	void printCode();
};
