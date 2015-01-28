/*
Code.cpp
Stores the code as a vector

Fouad Al-Rijleh, Rachel Rudolph
*/

#include "Code.h"
#include "d_except.h"

//Constructor that initializes vectors
Code::Code()
{
	score = 0;
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
	if (newCode.size() == LENGTH) code = newCode;
	else throw rangeError("vector must be of length " + to_string(LENGTH));
}

//Gets the code
vector<int> Code::getCode() const
{
	return code;
}

//Sets the used code vector
void Code::setUsedCode(vector<bool> newCode)
{
	if (newCode.size() == LENGTH) usedCode = newCode;
	else throw rangeError( "vector must be of length " + to_string(LENGTH) );
}

//Gets the used code vector
vector<bool> Code::getUsedCode() const
{
	return usedCode;
}

//Sets the score
void Code::setScore(int newScore)
{
	score = newScore;
}

//Gets the score
int Code::getScore() const
{
	return score;
}

//Generates the code randomly using the time as a seed
void Code::generateCode()
{
	srand(time(NULL));
	for (int i = 0; i < LENGTH; i++)
	{
		code[i] = rand() % (MAXNUMBER + 1) + MINNUMBER;
	}
}

//Counts the number of corrects digits in the correct location
int Code::checkCorrect(vector<int> guess)
{
	if (guess.size() != LENGTH)	throw rangeError("vector must be of length " + to_string(LENGTH));

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
	vector<bool> usedGuess;
	usedGuess = usedCode;

	if (guess.size() != LENGTH)	throw rangeError("vector must be of length " + to_string(LENGTH));

	for (int guessIndex = 0; guessIndex < LENGTH; guessIndex++)
	{
		if (usedGuess[guessIndex] == true) continue;
		for (int codeIndex = 0; codeIndex < LENGTH; codeIndex++) //Prevents using a guess digit that is already correct
		{
			if (guess[guessIndex] == code[codeIndex] && codeIndex != guessIndex && usedCode[codeIndex] == false)
			{
				usedCode[codeIndex] = true; //Prevents using the same code digit twice
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
void Code::printCode() const
{
	for (int i = 0; i < LENGTH; i++)
	{
		cout << code[i];
	}
	cout << endl;
}

//Increments the code
void Code::increment()
{
	int index = code.size() - 1;

	code[index]++;
	while (code[index] > MAXNUMBER) //Roll over single digit
	{
		code[index] = 0;
		if (index > 0) //Roll over non-most signficant digit
		{
			code[index - 1]++;
		}
		else //Roll over most significant bit
		{
			code.resize(4, 0);
			break;
		}
		index--;
	}
}

//Overload output operator for Code
ostream &operator<<(ostream &ostream, const Code &code)
{
	for (int index = 0; index < code.code.size(); index++)
	{
		ostream << code.code[index];
	}
	return ostream;
}

//Overload ++ operator for Code
void operator++(Code code)
{
	code.increment();
}