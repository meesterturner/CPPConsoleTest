#pragma once

#include <iostream>
#include <map>

using namespace std;

class Locale
{
public:
	Locale();
	char* getLocalisedString(string name);

private:
	map<string, string> localeDictionary;
	void loadLocale();
};