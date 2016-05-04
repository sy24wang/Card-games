#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Card.h"

using namespace std;

int randInt(int min, int max)
{
	srand (time(NULL));

	return rand() % max + min; 
}

Card::Card()
{
	int pattern = randInt(1, 4);
	int cardValue = randInt(1, 5);

	switch(pattern)
	{
		case 1: this->pattern = "Diamond"; break;
		case 2: this->pattern = "Club"; break;
		case 3: this->pattern = "Heart"; break;
		case 4: this->pattern = "Spade"; break;
		default: this->pattern = "ERROR";
	}
	this->cardValue = cardValue;

//TO DO: cards should follow singleton pattern
//we don't want 2X Diamond 4 appear at the same time

}

ostream &operator<<(ostream &out, const Card &other)
{
    out << "Card: " << other.pattern << " " << other.cardValue << endl;
    return out;
}