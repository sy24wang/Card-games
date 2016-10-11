#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include "Card.h"

using namespace std;

int Card::Facevalue(int card)
{
	int sub = card % 10;

	if (sub == 0)	//10, 20, 30, 40, or 50, which are meant to be reserved for the '5' in each suits, 0 is not used
	{
		return 5;
	}
	else if ((sub == 1) || (sub == 2) || (sub == 3))		//1, 2, 3, 11, 12, 13, 21, 22, 23... are reserved for the '1's in each suits
	{
		return 1;
	}
	else if ((sub == 4) || (sub == 5))		//4, 5, 14, 15, 24, 25... are reserved for the '2's in each suits
	{
		return 2;
	}
	else if ((sub == 6) || (sub == 7))   	//6, 7, 16, 17... are reserved for the '3's in each suits
	{
		return 3;
	}
	else if ((sub == 8) || (sub == 9))		//8, 9, 18, 19... are reserved for the '4's in each suits
	{
		return 4;
	}
	else									//otherwise, something went horribly wrong
	{
		return -999;
	}

}

Card::Card(int card)
{
	if ((card >= 1) && (card <= 10))
	{
		pattern = "White";
		cardValue = Facevalue(card);
	}
	else if ((card >= 11) && (card <= 20))
	{
		pattern = "Yellow";
		cardValue = Facevalue(card);
	}
	else if ((card >= 21) && (card <= 30))
	{
		pattern = "Green";
		cardValue = Facevalue(card);
	}
	else if ((card >= 31) && (card <= 40))
	{
		pattern = "Blue";
		cardValue = Facevalue(card);
	}
	else if ((card >= 41) && (card <= 50))
	{
		pattern = "Red";
		cardValue = Facevalue(card);
	}
	else
	{
		pattern = "ERROR";
		cardValue = -999;
	}
	indexValue = card;
	playable = false;
}

ostream &operator<<(ostream &out, const Card &other)
{
    out << "Pattern: " << other.pattern << ". Value: " << other.cardValue << ". Playable? " << other.playable << ". indexValue: " << other.indexValue << endl;
    return out;
}