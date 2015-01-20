/*
Code.cpp
Stores the code as a vector

Fouad Al-Rijleh, Rachel Rudolph
*/

#include "Code.h"

//Constructor that initializes vectors
Code::Code()
{
	vector<int> codeVector(LENGTH);
	setCode(codeVector);
	vector<bool> usedCode(LENGTH, false);
	setUsedCode(usedCode);
}

//Default destructor
Code::~Code()
{
}

//Sets the code
void Code::setCode(vector<int> newCode)
{
	if (newCode.size() == LENGTH)
	{
		code = newCode;
	}
	else "Input must be a vector of size LENGTH.";
}

//Gets the code
vector<int> Code::getCode()
{
	return code;
}

//Sets the used code vector
void Code::setUsedCode(vector<bool> newCode)
{
	if (newCode.size() == LENGTH)
	{
		usedCode = newCode;
	}
	else "Input must be a vector of size LENGTH.";
}

//Gets the used code vector
vector<bool> Code::getUsedCode()
{
	return usedCode;
}

//Generates the code randomly using the time as a seed
void Code::generateCode()
{
	srand(time(NULL));
	for (int i = 0; i < LENGTH; i++)
	{
		code[i] = rand() % MAXNUMBER;
	}
}

//Counts the number of corrects digits in the correct location
int Code::checkCorrect(vector<int> guess)
{
	int countCorrect = 0;
	for (int codeIndex = 0; codeIndex < LENGTH; codeIndex++)
	{
		if (code[codeIndex] == guess[codeIndex])
		{
			countCorrect++;
			usedCode[codeIndex] = true; //Prevents a correct guess from being recorded also as a incorrect guess
		}
	}
	return countCorrect;
}

//Counts the number of corrects digits in the incorrect location
int Code::checkIncorrect(vector<int> guess)
{
	int numberIncorrect = 0;

	for (int guessIndex = 0; guessIndex < LENGTH; guessIndex++)
	{
		for (int codeIndex = 0; codeIndex < LENGTH; codeIndex++)
		{
			if (guess[guessIndex] == code[codeIndex] && usedCode[codeIndex] == false && codeIndex != guessIndex)
			{
				usedCode[codeIndex] = true; //Prevents recording the same digit twice
				numberIncorrect++;
				break;
			}
		}
	}
	vector<bool> falseVector(4, false);
	setUsedCode(falseVector); //Resets the vector the counts what digits have been used
	return numberIncorrect;
}

//Prints the code
void Code::printCode()
{
	for (int i = 0; i < LENGTH; i++)
	{
		cout << code[i];
	}
	cout << endl;
}