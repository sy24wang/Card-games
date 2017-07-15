#include <iostream>
#include "player.h"
using namespace std;


Player::Player()
{
	card1.randomCard();
	card2.randomCard();
	card3.resetCard();
}

