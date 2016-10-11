#include <iostream>
#include "Card.h"
#include "Player.h"
#include "Infotoken.h"
#include "Fusetoken.h"
using namespace std;

int main()
{

	Player p1;
	cout << "Player 1: " << endl << p1;
	cout << "===============================\n";

	Player p2;
	cout << "Player 2: " << endl << p2;
	cout << "===============================\n";

	Player p3;
	cout << "Player 3: " << endl << p3;
	cout << "===============================\n";

	Player p4;
	cout << "Player 4: " << endl << p4;
	cout << "===============================\n";

	Information infotoken(8);
	Fuse fusetoken(3);

	infotoken.giveinfo();
	infotoken.giveinfo();

	fusetoken.wrongCardPlayed();

	p1.playCard(1);
	p1.playCard(1);
	p1.playCard(2);
}