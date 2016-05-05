#ifndef __CARD_H__
#define __CARD_H__

#include <iostream>
#include <vector>
class Card
{
	std::string pattern;
	int cardValue;
	
	int Facevalue(int card);

friend std::ostream &operator<<(std::ostream &out, const Card &c);

public:
	Card(int card);
	

};

#endif