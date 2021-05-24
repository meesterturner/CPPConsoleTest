#pragma once

#include <string>
#include "Locale.h"

using namespace std;

class HiScores
{
public:
	HiScores(Locale l);
	bool testScore(int score);
	void addScore(int score);
	void showScores();

private:
	int scores[4]; // 0-3
	string names[4]; // 0-3
	Locale locale;

};