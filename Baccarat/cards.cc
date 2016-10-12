#include <iostream>


#include "cards.h"
using namespace std;

Card::Card()
{
	score = 0;
	value = "X";
}

void Card::resetCard()
{
	score = 0;
	value = "X";
}

void Card::randomCard()
{		
	//generate number between 1 and 13
	int cardvalue = rand() % 13 + 1;

	if (cardvalue == 11)
	{
		score = 0;
		value = "J";
	}
	else if (cardvalue == 12)
	{
		score = 0;
		value = "Q";
	}
	else if (cardvalue == 13)
	{
		score = 0;
		value = "K";
	}
	else
	{
		score = cardvalue;
		value = inttostr(cardvalue);
	}
}