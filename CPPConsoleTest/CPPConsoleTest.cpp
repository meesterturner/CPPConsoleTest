// CPPConsoleTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Maths.h"
#include "Enums.h"
#include "Locale.h"
#include <map>




int main()
{
    MathsShiz maths;    
    GuessResult lastResult;
    Locale locale;

    maths.generateSecretNumber();
    lastResult = GuessResult::None;

    printf("%s\n\n", locale.getLocalisedString("Thought"));

    while (lastResult != GuessResult::JustRight)
    {
        int myGuess;

        printf("%s ", locale.getLocalisedString("Question"));
        scanf_s("%d", &myGuess);
        
        lastResult = maths.testGuess(myGuess);

        switch (lastResult)
        {
        case GuessResult::TooHigh:
            printf("\n%s\n", locale.getLocalisedString("TooHigh"));
            break;

        case GuessResult::TooLow:
            printf("\n%s\n", locale.getLocalisedString("TooLow"));
            break;

        }
    }

    printf("\n%s %d\n", locale.getLocalisedString("JustRight"), maths.getSecretNumber());

    return 0;
}
