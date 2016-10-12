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

bool Card::legalCard(string s)
{
	return ((s == "1") || (s == "2") || (s == "3") || (s == "4") || (s == "5") || 
			(s == "6") || (s == "7") || (s == "8") || (s == "9") || (s == "10") || 
			(s == "J") || (s == "Q") || (s == "K"));
}

