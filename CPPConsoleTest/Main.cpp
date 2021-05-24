// -----------------------------------------------------------
// Silly little C++ test program - "Guess The Number"
// (c) Paul Turner 2021
// -----------------------------------------------------------

#include <iostream>
#include "Maths.h"
#include "Enums.h"
#include "Locale.h"
#include "HiScores.h"
#include <map>

using namespace std;

int main()
{
    Maths maths;    
    GuessResult lastResult;
    Locale locale;
    HiScores hiscores(locale);

    int guesses;
    bool bored = false;


    while (!bored)
    {
        system("cls");

        maths.generateSecretNumber();
        lastResult = GuessResult::None;
        guesses = 0;

        printf("%s\n\n", locale.getLocalisedString("Thought"));

        while (lastResult != GuessResult::JustRight)
        {
            guesses++;
            int myGuess;

            printf("%s ", locale.getLocalisedString("Question"));
            cin >> myGuess;

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
        printf("\nYou scored %d\n\n", guesses);

        if (hiscores.testScore(guesses))
            hiscores.addScore(guesses);

        hiscores.showScores();

        string again;
        again = "";

        printf("%s", locale.getLocalisedString("PlayAgain"));
        cin >> again;

        if (again == "n" || again == "N")
            bored = true;
    }


    

    return 0;
}
