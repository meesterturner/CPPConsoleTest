#include <iostream>
#include <map>
#include "Locale.h"

using namespace std;

Locale::Locale() {
    Locale::localeDictionary["Thought"] = "I have thought of a number between 1 and 100!";
    Locale::localeDictionary["Question"] = "What number am I thinking of?";
    Locale::localeDictionary["TooHigh"] = "Your guess was too high";
    Locale::localeDictionary["TooLow"] = "Your guess was too low";
    Locale::localeDictionary["JustRight"] = "CONGRATULATIONS! Your guess was juuuuust right! It was ";
}

char* Locale::getLocalisedString(string name) {
    char* temp = _strdup(Locale::localeDictionary[name].c_str());
    return temp;
};