#include <string>
#include "Locale.h"
#include "HiScores.h"


using namespace std;

HiScores::HiScores(Locale l)
{
	locale = l;

	scores[0] = 5;
	scores[1] = 10;
	scores[2] = 15;
	scores[3] = 20;

	names[0] = "One";
	names[1] = "Two";
	names[2] = "Three";
	names[3] = "Four";
}

bool HiScores::testScore(int score)
{
	if (score < scores[3])
		return true;

	return false;
}

void HiScores::addScore(int score)
{
	string name;

	printf("%s ", locale.getLocalisedString("EnterScore"));
	cin >> name;

	// Get position in table
	int pos = -1;
	for (int i = 0; i <= 3; i++)
	{
		if (score < scores[i])
		{
			pos = i;
			break;
		}
	}

	// Move everything down
	for (int i = 3; i > pos; i--)
	{
		scores[i] = scores[i - 1];
		names[i] = names[i - 1];
	}

	// Insert
	scores[pos] = score;
	names[pos] = name;
}

void HiScores::showScores()
{
	system("cls");

	printf("\n\n--------------------------------------------------\n");
	for (int i = 0; i <= 3; i++)
	{
		string name = names[i];
		int score = scores[i];
		printf(" %d. %s: %d\n", i, names[i].c_str(), scores[i]);
	}
	printf("--------------------------------------------------\n\n");
}