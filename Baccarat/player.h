#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "cards.h"
class Player
{
	int numOfWin;
	int score;
	Card card1;
	Card card2;
	Card card3;

public:
	Player();

friend class Game;
};

#endif