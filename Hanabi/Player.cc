#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Card.h"

using namespace std;

int *used = new int[21];		//[0] is not used, [1]-[5]= Diamond, [6]-[10]=Club, [11]-[15]=Heart, [16]-[20]=Spade


int randInt(int min, int max)
{

	return rand() % max + min; 
}

void Player::init()
{
	for (int i = 0; i < 21; i++)
	{
		used[i] = 0;
	}
}

int Player::CardGen()
{
	const bool DEBUG = false;
	
	int card = randInt(1, 20);
	if (DEBUG)
	{
		cout << "Generated card: " << card << endl;
	}
	while(used[card] == 1)
	{
		card = randInt(1, 20);
		if (DEBUG)
		{
			cout << "Card already used, generating new card: " << card << endl;
		}
	}
	used[card] = 1;
	return card;
}

Player::Player()
{
	int card;
	card = CardGen();
	c1 = new Card(card);

	card = CardGen();
	c2 = new Card(card);

	card = CardGen();
	c3 = new Card(card);

	card = CardGen();
	c4 = new Card(card);

	card = CardGen();
	c5 = new Card(card);
}

ostream &operator<<(ostream &out, const Player &other)
{
    out << *(other.c1) << *(other.c2) << *(other.c3) << *(other.c4) << *(other.c5);
    return out;
}