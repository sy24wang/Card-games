#include <iostream>
#include "game.h"
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

void Game::newGame()
{
	//Tester
	infotoken->giveinfo();
	infotoken->giveinfo();

	fusetoken->wrongCardPlayed();

	p1.playCard("play", 1);
	p1.playCard("play", 1);
	p1.playCard("play", 2);
	p1.playCard("play", 5);
	p1.playCard("play", 8);
	p2.playCard("play", 9);
}