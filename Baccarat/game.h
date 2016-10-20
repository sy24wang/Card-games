#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include "player.h"

class Game
{
	Player p;
	Player ai;
	bool cheat;
	int money;

public:
	void compare(struct Player *p, struct Player *ai);
	bool legalCard(std::string s);
	int finalscore(int total);
	bool drawThird(int player, int ai);
	int strtoint(std::string str);
	void setMoney(int n);
	Game();
	void startGame();

};

#endif