#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include "Player.h"
#include "Infotoken.h"
#include "Fusetoken.h"

class Game
{
	Player p1;
	Player p2;
	Player p3;
	Player p4;
	Information *infotoken;
	Fuse *fusetoken;
public:
	Game();
	void newGame();

};


#endif