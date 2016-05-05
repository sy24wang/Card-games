#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include "Card.h"

using namespace std;

Card::Card(int card)
{
	numericalAlias = card;
	if ((card >= 1) && (card <= 5))
	{
		pattern = 1;
		cardValue = card;
	}
	else if ((card >= 6) && (card <= 10))
	{
		pattern = 2;
		cardValue = card - 5;
	}
	else if ((card >= 11) && (card <= 15))
	{
		pattern = 3;
		cardValue = card - 10;
	}
	else if ((card >= 16) && (card <= 20))
	{
		pattern = 4;
		cardValue = card - 15;
	}
	else if ((card >= 21) && (card <= 25))
	{
		pattern = 5;
		cardValue = card - 20;
	}
	else
	{
		pattern = -999;
		cardValue = -999;
	}
}

ostream &operator<<(ostream &out, const Card &other)
{
	switch (other.pattern)
	{
		case 1: out << "White "; break;
		case 2: out << "Yellow "; break;
		case 3: out << "Green "; break;
		case 4: out << "Blue "; break;
		case 5: out << "Red "; break;
		default: out << "ERROR "; break;
	}
    out << other.cardValue << endl;
    return out;
}