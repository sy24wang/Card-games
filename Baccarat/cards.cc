#include <iostream>


#include "cards.h"
using namespace std;

Card::Card()
{
	cout << "3\n";
	score = 0;
	value = "N/A";
}


void Card::randomCard()
{		
	cout << "rc\n";
	//generate number between 1 and 13
	int cardvalue = rand() % 13 + 1;

	Card *newcard = new Card();

	if (cardvalue == 11)
	{
		value = "J";
	}
	else if (cardvalue == 12)
	{
		value = "Q";
	}
	else if (cardvalue == 13)
	{
		value = "K";
	}
	else
	{
		value = inttostr(cardvalue);
	}
}

bool Card::legalCard(string s)
{
	return ((s == "1") || (s == "2") || (s == "3") || (s == "4") || (s == "5") || 
			(s == "6") || (s == "7") || (s == "8") || (s == "9") || (s == "10") || 
			(s == "J") || (s == "Q") || (s == "K"));
}

bool Card::drawThird(int player, int ai)
{
	bool match_one = (ai <= 2);											//if bank is <= 2, then draw
	bool match_two = ((ai == 3) && (player != 8));						//if bank is 3, then draw unless player drew an 8 as third card
	bool match_three = ((ai == 4) && (player >= 2) && (player <= 7));	//if bank is 4, then draw if player drew 2-7
	bool match_four = ((ai == 5) && (player >= 4) && (player <= 7));	//if bank is 5, then draw if player drew 4-7
	bool match_five = ((ai == 6) && (player >= 6) && (player <= 7));	//if bank is 6, then draw if player drew 6 or 7
																		//if bank is 7, then the banker stands 
	return (match_one || match_two || match_three || match_four || match_five);
}
