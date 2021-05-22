#pragma once

enum class GuessResult;
class MathsShiz
{
public:
	void generateSecretNumber();
	GuessResult testGuess(int guess);
	int getSecretNumber();

private:
	int secretNumber;
};
