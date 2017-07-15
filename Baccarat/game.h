#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include "player.h"

class Game
{
	Player p;
	Player ai;
	bool cheat;
	int totalmoney;
	int bet;
public:
	void selectCheat(int cheatmode);
	void compare(Player *p, Player *ai);
	int finalscore(int total);
	bool drawThird(int player, int ai);
	Game();
	void startGame();
};

#endif