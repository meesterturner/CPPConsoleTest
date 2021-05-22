// CPPConsoleTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Maths.h"
#include "Enums.h"


int main()
{
    MathsShiz maths;
    maths.generateSecretNumber();
    GuessResult lastResult;

    lastResult = GuessResult::None;

    printf("I have thought of a number between 1 and 100!\n\n");

    while (lastResult != GuessResult::JustRight)
    {
        int myGuess;

        printf("What number am I thinking of? ");
        scanf_s("%d", &myGuess);
        
        lastResult = maths.testGuess(myGuess);

        switch (lastResult)
        {
        case GuessResult::TooHigh:
            printf("\nYour guess was too high\n");
            break;

        case GuessResult::TooLow:
            printf("\nYour guess was too low\n");
            break;

        }
    }

    printf("\nCONGRATULATIONS! Your guess was juuuuust right! It was %d\n", maths.getSecretNumber());

    return 0;
}
