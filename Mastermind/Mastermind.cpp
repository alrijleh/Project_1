/*
Mastermind.cpp
Handles the game mechanics

Fouad Al-Rijleh, Rachel Rudolph
*/

#include "Mastermind.h"

using namespace std;

//Constructor that initializes variables
Mastermind::Mastermind()
{
	Code secretCode;
	Code humanGuess;
}

//Default destructor
Mastermind::~Mastermind()
{
}

//Reads user input from console and checks validity
Code Mastermind::humanGuess()
{
	//Add checks for edge cases
	char userInput[1024];
	cout << "Enter 4 digits: ";

	vector<int> userVector(4);
	Code userCode;
	int stringIndex = 0;
	int temp;

	while (true)
	{
		temp = getchar() - '0';
		if (temp >= MINNUMBER && temp < MAXNUMBER)
		{
			userVector[stringIndex] = temp;
			stringIndex++;
		}
		if (stringIndex == LENGTH) break;

	}

	userCode.setCode(userVector);
	return userCode;
}

//Gets response based on current guess
Response Mastermind::getResponse(Code userCode, Code secretCode)
{
	Response response;
	vector<int> userVector = userCode.getCode();
	response.setNumCorrect( secretCode.checkCorrect(userVector) );
	response.setNumIncorrect( secretCode.checkIncorrect(userVector) );
	return response;
}

//Implements the game 
void Mastermind::playGame()
{
	Response response;
	secretCode.generateCode();
	cout << "Secret Code: ";
	printCode();

	while (true)
	{
		Code guess = humanGuess();
		cout << "User Guess: ";
		guess.printCode();
		response = getResponse(guess, secretCode);
		response.printResponse();
		if ( response.checkSolve() )
		{
			cout << "Correct!" << endl;
			break;
		}
	}
}

//Prints secret code
void Mastermind::printCode()
{
	vector<int> codeVector = secretCode.getCode();
	for (int i = 0; i < LENGTH; i++)
	{
		cout << codeVector[i];
	}
	cout << endl;
}