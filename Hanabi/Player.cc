#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Card.h"
#include <algorithm>

using namespace std;

int *used = new int[51];


int randInt(int min, int max)
{

	return rand() % max + min; 
}

void Player::init()
{
	for (int i = 0; i < 51; i++)
	{
		used[i] = 0;
	}
}

int Player::CardGen()
{
	int card = randInt(1, 50);
	if (DEBUG)
	{
		cout << "Generated card: " << card << endl;
	}
	while(used[card] == 1)
	{
		card = randInt(1, 50);
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
	DEBUG = false;
	int card;
	card = CardGen();
	c1 = new Card(card);
	playerHand.push_back(*c1);

	card = CardGen();
	c2 = new Card(card);
	playerHand.push_back(*c2);

	card = CardGen();
	c3 = new Card(card);
	playerHand.push_back(*c3);

	card = CardGen();
	c4 = new Card(card);
	playerHand.push_back(*c4);

	card = CardGen();
	c5 = new Card(card);
	playerHand.push_back(*c5);
}

//Note: playCard takes in the literal (physical) index, forget about index 0
//You'd say I want to "play card #1", not "play card #0" in real-life

void Player::playCard(int handindex)
{
	//Play a card
	/*
	if (wrongcard)
	Fuse.wrongCardPlayed
	*/

	//finding out which card exactly that got played
	Card *temp;
	switch(handindex)
	{
		case 1:
			temp = c1;
			break;
		case 2:
			temp = c2;
			break;
		case 3:
			temp = c3;
			break;
		case 4:
			temp = c4;
			break;
		case 5:
			temp = c5;
			break;
		default:
			temp = NULL;
			cout << "ERROR: Player::playCard's index out of bounds...can't play" << endl;
			return;
	}


	//It's been played, so it's unavailable for drawing (Just played Green 5 which only got 1 copy, can't draw Green 5 again)
	int playedvalue = temp->indexValue;
	cout << "The card got played was: " << *temp << endl;
	used[playedvalue] = 1;


	//Delete this card from my hand
	playerHand.erase(playerHand.begin() + (handindex - 1));		//ex. played card #5, we want to erase playerHand[4]
	//delete(playerHand.begin() + (handindex - 1));

	//Draw a card
	int card = CardGen();
	Card *newcard = new Card(card);
	cout << "Drew card: " << *newcard << endl;

	*temp = *newcard;
	cout << "Current hand: " << endl;
	cout << *this;
}

ostream &operator<<(ostream &out, const Player &other)
{
    out << *(other.c1) << *(other.c2) << *(other.c3) << *(other.c4) << *(other.c5);
    return out;
}