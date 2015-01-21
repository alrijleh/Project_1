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
	vector<int> userVector(4);
	Code userCode;
	string userInput;
	int digit;

	while (true)
	{
		cout << endl << "Enter 4 digits: ";
		getline(cin, userInput);

		if (userInput.size() != LENGTH){
			cout << "Error: Code must be 4 characters long" << endl;
			continue;
		}

		for (int charIndex = 0; charIndex < userInput.size(); charIndex++)
		{
			digit = userInput[charIndex] - '0';
			if (digit >= MINNUMBER && digit <= MAXNUMBER)
			{
				userVector[charIndex] = digit;

				if (charIndex + 1 == LENGTH && userInput.size() == LENGTH)
				{
					userCode.setCode(userVector);
					return userCode;
				}
			}
			else
			{
				cout << "Error: Code must consist of numbers between " << MINNUMBER << " and " << MAXNUMBER << endl;
				break;
			}
		}
	}
}

//Gets response based on current guess
Response Mastermind::getResponse(Code userCode, Code secretCode)
{
	Response response;
	vector<int> userVector = userCode.getCode();
	response.setNumCorrect(secretCode.checkCorrect(userVector));
	response.setNumIncorrect(secretCode.checkIncorrect(userVector));
	return response;
}

//Check if guess is correct
bool Mastermind::checkSolve(Response response)
{
	if (response.getNumCorrect() == LENGTH) return true;
	else return false;
}

//Implements the game 
void Mastermind::playGame()
{
	Response response;
	secretCode.generateCode();
	cout << "Secret Code is: ";
	printCode();

	while (true)
	{
		Code guess = humanGuess();
		response = getResponse(guess, secretCode);
		response.printResponse();
		if (checkSolve(response))
		{
			cout << endl << "Correct!" << endl;
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
