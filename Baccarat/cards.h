#ifndef __CARDS_H__
#define __CARDS_H__

#include <iostream>
#include <cstdlib>
#include <sstream>

class Card
{

	int score;
	std::string value;

public:
	std::string inttostr(int n);
	void randomCard();
	void resetCard();
	Card();
friend class Game;
friend class Player;

};



#endif