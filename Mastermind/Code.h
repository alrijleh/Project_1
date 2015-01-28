/*
Code.h
Stores the code as a vector

Fouad Al-Rijleh, Rachel Rudolph
*/

#pragma once

#include "Constants.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Code
{
private:
	int score;
	vector<int> code;
	vector<bool> usedCode; //This array records if a digit in the code have been used in the check functions

public:
	Code();
	~Code();

	void setCode(vector<int> newCode);
	vector<int> getCode() const;
	void setUsedCode(vector<bool> newCode);
	vector<bool> getUsedCode() const;
	void setScore(int newScore);
	int getScore() const;


	void generateCode();
	int checkCorrect(vector<int> guess);
	int checkIncorrect(vector<int> guess);
	void printCode() const;
	void increment();

	friend ostream &operator<<(ostream &ostream, const Code &code);
	friend void operator++(Code code);
};