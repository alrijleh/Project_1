/*
Mastermind.h
Handles the game mechanics

Fouad Al-Rijleh, Rachel Rudolph
*/

#include "Constants.h"
#include "Code.h"
#include "Response.h"
#include "Container.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Mastermind
{
private:
	Code guessCode;
	Code secretCode;
	Response response;
	vector<Container> history;
	vector<Response> allResponses;
public:
	Mastermind();
	~Mastermind();

	void setUserCode(Code newUserCode);
	Code getUserCode() const;

	void setSecretCode(Code newSecretCode);
	Code getSecretCode() const;

	Response generateResponse(Code guessCode, Code secretCode) const;
	Code humanGuess();
	Code agentGuess();
	
	int calculateScore(Code guess) const;
	bool consistentWithPreviousGuesses(Code currentGuess) const;
	bool checkSolve(Response response) const;
	void playGame();
	void playGame2();

	void printCode() const;
	friend ostream &operator<<(ostream &ostream, const Mastermind &mastermind);
};
