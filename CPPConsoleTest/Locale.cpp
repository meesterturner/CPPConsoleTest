#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "Locale.h"


using namespace std;

Locale::Locale() {
    loadLocale();
}

char* Locale::getLocalisedString(string name) {
    char* temp = _strdup(Locale::localeDictionary[name].c_str());
    return temp;
};

void Locale::loadLocale()
{

    ifstream inFile;
    inFile.open("Locale.txt");
    if (!inFile)
    {
        cerr << "Unable to open file";
        exit(1); // returncode 1
    }

    string line;
    string delim = "|";
    string key;
    string sentence;

    while (getline(inFile, line))
    {
        key = line.substr(0, line.find(delim));
        sentence = line.erase(0, line.find(delim) + delim.length());

        Locale::localeDictionary[key] = sentence;
    }

    inFile.close();
};