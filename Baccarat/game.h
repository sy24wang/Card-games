#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include "player.h"

extern int strtoint(std::string s);

class Game
{
	Player p;
	Player ai;
	bool cheat;
	int totalmoney;
	int bet;
public:
	void compare(struct Player *p, struct Player *ai);
	bool legalCard(std::string s);
	int finalscore(int total);
	bool drawThird(int player, int ai);
	void writeMoney(int n);
	void loadMoney();
	Game();
	void startGame();

};

#endif