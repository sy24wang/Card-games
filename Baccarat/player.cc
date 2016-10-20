#include <iostream>
#include "player.h"
using namespace std;


Player::Player()
{
	int score = 0;
	card1.randomCard();
	card2.randomCard();
	card3.resetCard();
}

