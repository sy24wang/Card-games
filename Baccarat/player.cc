#include <iostream>
#include "player.h"
using namespace std;


Player::Player()
{
	numOfWin = 0;
	int score = 0;
	card1.randomCard();
	card2.randomCard();
	card3.score = 0;
	card3.value = "X";
}

