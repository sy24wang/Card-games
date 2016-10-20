#ifndef __CARDS_H__
#define __CARDS_H__

#include <iostream>
#include <cstdlib>
#include <sstream>

extern std::string inttostr(int n);

class Card
{
	int score;
	std::string value;

public:
	void randomCard();
	void resetCard();
	Card();

friend class Game;
};

#endif