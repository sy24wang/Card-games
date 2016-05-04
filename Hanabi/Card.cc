#include <iostream>
#include <sstream>
#include <string>
#include "Card.h"

using namespace std;

Card::Card(int card)
{

	if ((card >= 1) && (card <= 5))
	{
		pattern = "Diamond";
		cardValue = card;
	}
	else if ((card >= 6) && (card <= 10))
	{
		pattern = "Club";
		cardValue = card - 5;
	}
	else if ((card >= 11) && (card <= 15))
	{
		pattern = "Heart";
		cardValue = card - 10;
	}
	else if ((card >= 16) && (card <= 20))
	{
		pattern = "Spade";
		cardValue = card - 15;
	}
	else
	{
		pattern = "ERROR";
		cardValue = -999;
	}
}

ostream &operator<<(ostream &out, const Card &other)
{
    out << other.pattern << " " << other.cardValue << endl;
    return out;
}