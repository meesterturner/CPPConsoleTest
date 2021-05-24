#include <time.h>
#include <stdlib.h>
#include "Maths.h"
#include "Enums.h"

void Maths::generateSecretNumber()
{
	srand(time(NULL));
	secretNumber = -1;

	while (secretNumber < 1 || secretNumber > 100)
	{
		secretNumber = rand() % 99;
	}
}

GuessResult Maths::testGuess(int guess)
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

int Maths::getSecretNumber()
{
	return secretNumber;
}

