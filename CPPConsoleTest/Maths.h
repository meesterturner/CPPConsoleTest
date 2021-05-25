#pragma once
#include "Enums.h"

class Maths
{
public:
	void generateSecretNumber();
	GuessResult testGuess(int guess);
	int getSecretNumber();
	int lowerTest();

private:
	int secretNumber;
};
