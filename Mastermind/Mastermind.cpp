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
	Mastermind::setUserCode(guessCode);
	Mastermind::setSecretCode(secretCode);

	//Generate vector of possible responses
	Response possibleResponse;
	allResponses.reserve(LENGTH*(LENGTH + 1) / 2); //Total possibilities is the LENGTH triangular number
	for (int numCorrect = 0; numCorrect <= LENGTH; numCorrect++)
	{
		for (int numIncorrect = 0; numIncorrect <= (LENGTH - numCorrect); numIncorrect++)
		{
			possibleResponse.setNumCorrect(numCorrect);
			possibleResponse.setNumIncorrect(numIncorrect);
			allResponses.push_back(possibleResponse);
		}
	}
}

//Default destructor
Mastermind::~Mastermind()
{
}

//Sets the guessCode
void Mastermind::setUserCode(Code newUserCode)
{
	guessCode = newUserCode;
}

//Sets the secretCode
void Mastermind::setSecretCode(Code newSecretCode)
{
	secretCode = newSecretCode;
}

//Gets the guessCode
Code Mastermind::getUserCode() const
{
	return guessCode;
}

//Gets the guessCode
Code Mastermind::getSecretCode() const
{
	return secretCode;
}

//Reads user input from console and checks validity
Code Mastermind::humanGuess()
{
	vector<int> userVector(4);
	Code guessCode;
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
					guessCode.setCode(userVector);
					return guessCode;
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

//Generates the guess for the computer based on past responses
Code Mastermind::agentGuess()
{
	if (history.size() == 0) //No history to base guess off of
	{
		guessCode.generateCode();
		return guessCode;
	}

	int score = 0, lowestScore = 0;
	Code possibleGuess, lowestScoreGuess;

	while (true)
	{
		//calculate score if consistent 
		if (consistentWithPreviousGuesses(possibleGuess))
		{
			score = calculateScore(possibleGuess);
			//if lowest score, save guess
			if (score < lowestScore && lowestScore != 0 && score != 0)
			{
				lowestScore = score;
				lowestScoreGuess.setCode(possibleGuess.getCode());
			}
		}

		//if lowest score, save guess
		if (score < lowestScore && lowestScore != 0 && score != 0)
		{
			lowestScore = score;
			lowestScoreGuess.setCode(possibleGuess.getCode());
		}

		//Increment through all possible codes
		possibleGuess.increment();
		if ( possibleGuess.isZero() ) break;
	}

	return lowestScoreGuess;
}

int Mastermind::calculateScore(Code &guess)
{
	Code possibleNextGuess;
	int score = 0;

	cout << "calculateScore()" << endl;

	for (int responseIndex = 0; responseIndex < allResponses.size(); responseIndex++)
	{
		while (true)
		{
			if (consistentWithPreviousGuesses(possibleNextGuess))
			{
				score++;
			}

			//Loop through all possible guesses
			possibleNextGuess.increment();
			if (possibleNextGuess.isZero()) break;
		}
	}

	return score;
}

//Generates a response between two guesses
Response Mastermind::generateResponse(Code &guessCode, Code &secretCode) const
{
	Response response;
	vector<int> userVector = guessCode.getCode();
	response.setNumCorrect(secretCode.checkCorrect(userVector));
	response.setNumIncorrect(secretCode.checkIncorrect(userVector));
	return response;
}

//Check if guess is correct
bool Mastermind::checkSolve(Response response) const
{
	if (response.getNumCorrect() == LENGTH) return true;
	else return false;
}

//Returns true if guess response is consistent with previous responses
bool Mastermind::consistentWithPreviousGuesses(Code &currentGuess) const
{
	Response theoreticalResponse, pastResponse;
	Code pastGuess;
	
	if (history.size() == 0) return true;
	
	for (int round = 0; round < history.size(); round++)
	{
		pastGuess = history[round].getGuessCode();
		pastResponse = history[round].getResponse();
		theoreticalResponse = generateResponse(currentGuess, pastGuess);

		if (theoreticalResponse != pastResponse) return false;
	}
	return true;
}

//Implements the game with the user guessing
void Mastermind::playGame()
{
	secretCode.generateCode();
	cout << "Secret Code is: " << secretCode;

	while (true)
	{
		Code guess = humanGuess();
		response = generateResponse(guess, secretCode);
		cout << response << endl;
		if (checkSolve(response))
		{
			cout << endl << "Correct!" << endl;
			break;
		}
	}
}

//Implements the game with the computer guessing
void Mastermind::playGame2()
{
	cout << "Enter secret code" << endl;
	secretCode = humanGuess();

	while (true)
	{

		guessCode = agentGuess();
		response = generateResponse(guessCode, secretCode);
		Container container(guessCode, response);
		history.push_back(container);
		
		cout << guessCode << endl;
		cout << response << endl;

		//Check for winning condition
		if (checkSolve(response))
		{
			cout << "correct" << endl;
			cout << "solved in " << history.size() << " turns" << endl;
			break;
		}
	}
}

//Prints secret code
void Mastermind::printCode() const
{
	vector<int> codeVector = secretCode.getCode();
	for (int i = 0; i < LENGTH; i++)
	{
		cout << codeVector[i];
	}
	cout << endl;
}

//Overload output operator for Mastermind to print secretCode
ostream &operator<<(ostream &ostream, const Mastermind &mastermind)
{
	ostream << mastermind.getSecretCode();
	return ostream;
}