#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "Card.h"



class Player
{
	Card *c1 = NULL;
	Card *c2 = NULL;
	Card *c3 = NULL;
	Card *c4 = NULL;
	Card *c5 = NULL;
	int CardGen();

friend std::ostream &operator<<(std::ostream &out, const Player &p);

public:
	Player();
	void init();

};

#endif