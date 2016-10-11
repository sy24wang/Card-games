#include <iostream>
#include "game.h"
#include "Player.h"
using namespace std;

Game::Game()
{
	cout << "===============================\n";
	
	cout << "Player 1: " << endl << p1;
	cout << "===============================\n";

	cout << "Player 2: " << endl << p2;
	cout << "===============================\n";

	cout << "Player 3: " << endl << p3;
	cout << "===============================\n";

	cout << "Player 4: " << endl << p4;
	cout << "===============================\n";
	
	infotoken = new Information(8);
	fusetoken = new Fuse(3);
}