#include <time.h>
#include <stdlib.h>
#include "Maths.h"
#include "Enums.h"

void MathsShiz::generateSecretNumber()
{
	srand(time(NULL));
	secretNumber = rand() % 99;
}

GuessResult MathsShiz::testGuess(int guess)
{
	GuessResult retVal = GuessResult::JustRight;

	if (guess > secretNumber)
	{
		retVal = GuessResult::TooHigh;
	}
	else if (guess < secretNumber)
	{
		retVal = GuessResult::TooLow;
	}

	return retVal;
}

int MathsShiz::getSecretNumber()
{
	return secretNumber;
}
