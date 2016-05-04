#ifndef __CARD_H__
#define __CARD_H__

#include <iostream>
#include <vector>
class Card
{
	int pattern;
	int cardValue;
	


friend std::ostream &operator<<(std::ostream &out, const Card &c);

public:
	Card(int card);
	int numericalAlias;
	

};

#endif