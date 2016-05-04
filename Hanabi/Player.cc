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

Player::Player()
{

	int card = randInt(1, 20);
	cout << "c1 = " << card << endl;
	while(used[card] == 1)
	{
		card = randInt(1, 20);
		cout << "regen c1, new c1 = " << card << endl;
	}
	c1 = new Card(card);
	used[card] = 1;


	card = randInt(1, 20);
	cout << "c2 = " << card << endl;
	while(used[card] == 1)
	{
		card = randInt(1, 20);
				cout << "regen c2, new c2 = " << card << endl;
	}
	c2 = new Card(card);
	used[card] = 1;


	card = randInt(1, 20);
	cout << "c3 = " << card << endl;
	while(used[card] == 1)
	{
		card = randInt(1, 20);
				cout << "regen c3, new c3 = " << card << endl;
	}
	c3 = new Card(card);
	used[card] = 1;


	card = randInt(1, 20);
	cout << "c4 = " << card << endl;
	while(used[card] == 1)
	{
		card = randInt(1, 20);
				cout << "regen c4, new c4 = " << card << endl;
	}
	c4 = new Card(card);
	used[card] = 1;


	card = randInt(1, 20);
	cout << "c5 = " << card << endl;
	while(used[card] == 1)
	{
		card = randInt(1, 20);
				cout << "regen c5, new c5 = " << card << endl;
	}
	c5 = new Card(card);
	used[card] = 1;
}

ostream &operator<<(ostream &out, const Player &other)
{
    out << "Player: " << *(other.c1) << *(other.c2) << *(other.c3) << *(other.c4) << *(other.c5);
    return out;
}