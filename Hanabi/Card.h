#ifndef __CARD_H__
#define __CARD_H__

#include <iostream>
#include <vector>
class Card
{
	std::string pattern;

	int Facevalue(int card);
	bool playable;
	int faceValue;
	int indexValue;
friend std::ostream &operator<<(std::ostream &out, const Card &c);

public:
	Card(int card);
	int getIndexValue();
};

#endif