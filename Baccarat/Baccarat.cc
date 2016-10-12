#include <iostream>
#include <time.h>
#include "game.h"

using namespace std;

void printrule()
{
	std::cout << "Rule:\n";
	std::cout << "\tEach player will draw 2 cards\n";
	std::cout << "\tYour score is the last digit of the sum\n";
	std::cout << "\tFor example, 9 and 4 makes 13 = 3. 3 and 8 makes 11 = 1)\n";
	std::cout << "\tA 10 or a picture (J, Q, K) counts as 0\n";
	std::cout << "\tIf either side's score is 8 or 9 after revealing two cards, the game is over\n";
	std::cout << "\tIf not, one more card may be drawn\n";
	std::cout << "\tThe winner is the one with score closest to 9\n";
}

int main()
{
	srand(time(NULL));
	int menuselection;
	int cheatmodeselection;
	Game g;
	cout << "Welcome to Bacarrat!" << endl;
	printrule();

	g.startGame();
}
