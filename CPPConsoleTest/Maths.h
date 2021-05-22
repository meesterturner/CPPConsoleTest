#pragma once
#include "Enums.h"

class MathsShiz
{
public:
	void generateSecretNumber();
	GuessResult testGuess(int guess);
	int getSecretNumber();

private:
	int secretNumber;
};
