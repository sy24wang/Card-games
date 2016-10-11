#include <iostream>
#include "game.h"
using namespace std;

int main()
{

	Game *newGame = new Game();

	newGame->infotoken->giveinfo();
	newGame->infotoken->giveinfo();

	newGame->fusetoken->wrongCardPlayed();

	newGame->p1.playCard("play", 1);
	newGame->p1.playCard("play", 1);
	newGame->p1.playCard("play", 2);
}