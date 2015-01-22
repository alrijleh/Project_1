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
	vector<int> code;
	vector<bool> usedCode; //This array records if a digit in the code have been used in the check functions

public:
	Code();
	~Code();

	friend ostream &operator<<(ostream &ostream, const Code &code);

	void setCode(vector<int> newCode);
	vector<int> getCode();
	void setUsedCode(vector<bool> newCode);
	vector<bool> getUsedCode();

	void generateCode();
	int checkCorrect(vector<int> guess);
	int checkIncorrect(vector<int> guess);
	void printCode();

	void increment();
};