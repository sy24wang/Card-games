#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include "player.h"

class Game
{
	Player p;
	Player ai;
	bool cheat;

public:
	void compare(struct Player *p, struct Player *ai);
	bool legalCard(std::string s);
	int finalscore(int total);
	bool drawThird(int player, int ai);
	int strtoint(std::string str);

	Game();
	void startGame();

};

#endif