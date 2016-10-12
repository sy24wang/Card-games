#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include "player.h"

class Game
{
	public:
	Player p;
	Player ai;
	bool cheat;
	void compare(struct Player *p, struct Player *ai);

	Game();
	void startGame();

	int finalscore(int total)
	{
		return total % 10;
	}
	//"J", "Q", "K" will fail, so it will return 0
	int strtoint(std::string str)
	{
	    int num;
	    std::istringstream(str) >> num;
	    return num;
	}


};

#endif