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

	Mastermind::setUserCode(guessCode);
	Mastermind::setSecretCode(secretCode);
}

//Default destructor
Mastermind::~Mastermind()
{
}

//Sets the guessCode
void Mastermind::setUserCode(Code newUserCode)
{
	if (newUserCode.getCode() != guessCode.getCode())
	{
		guessCode = newUserCode;
	}
	else "Input must be a CODE object of size LENGTH.";
}

//Sets the secretCode
void Mastermind::setSecretCode(Code newSecretCode)
{
	if (newSecretCode.getCode() != secretCode.getCode())
	{
		secretCode = newSecretCode;
	}
	else "Input must be a CODE object of size LENGTH.";
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

	vector<Response> allResponses(15);
	Response possibleResponse;
	for (int responseIndex = 0; responseIndex < allResponses.size(); responseIndex++)
	{
		for (int numCorrect = 0; numCorrect <= LENGTH; numCorrect++)
		{
			for (int numIncorrect = 0; numIncorrect <= LENGTH - numCorrect; numIncorrect++)
			{
				possibleResponse.setNumCorrect(numCorrect);
				possibleResponse.setNumIncorrect(numIncorrect);
				allResponses[responseIndex] = possibleResponse;
			}
		}
	}

	vector<int> scores(15);
	Code guess;
	vector<int> zero(LENGTH);
	for (int responseIndex = 0; responseIndex < allResponses.size(); responseIndex++)
	{
		while (true)
		{
			if (consistentWithPreviousGuesses(guess))
			{
				scores[responseIndex]++;
			}
			guess.increment();

			if (guess.getCode() == zero) break;
		}
	}
	

}

//Gets response based on current guess
Response Mastermind::generateResponse(Code guessCode, Code secretCode) const
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
bool Mastermind::consistentWithPreviousGuesses(Code currentGuess) const
{
	int numCorrect, numIncorrect;
	Response theoreticalResponse, pastResponse;
	Code pastGuess;

	for (int round = 0; round < history.size(); round++)
	{
		pastGuess = history[round].getGuessCode();
		pastResponse = history[round].getResponse();
		numCorrect = pastGuess.checkCorrect(currentGuess.getCode());
		numIncorrect = pastGuess.checkIncorrect(currentGuess.getCode());
		theoreticalResponse = generateResponse(currentGuess, pastGuess);

		if (!theoreticalResponse.isEqual(pastResponse)) return false;
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
	//secretCode.generateCode();
	cout << "Enter secret code" << endl;
	secretCode = humanGuess();


	while (true)
	{
		guessCode = agentGuess();
		response = generateResponse(guessCode, secretCode);
		Container container(guessCode, response);
		history.push_back(container);

		system("pause");

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
