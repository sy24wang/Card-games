#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "Card.h"
#include <vector>


class Player
{
	Card *c1 = NULL;
	Card *c2 = NULL;
	Card *c3 = NULL;
	Card *c4 = NULL;
	Card *c5 = NULL;
	std::vector <Card> playerHand;

	void Sorthand(std::vector<Card> *playerHand);
	int CardGen();

friend std::ostream &operator<<(std::ostream &out, const Player &p);

public:
	Player();
	void init();

};

struct comparison
{
	inline bool operator() (const Card& c1, const Card& c2)
	{
		return (c1.numericalAlias < c2.numericalAlias);
	}

};

#endif