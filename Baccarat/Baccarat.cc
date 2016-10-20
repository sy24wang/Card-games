#include <iostream>
#include <time.h>
#include "game.h"

using namespace std;

void printrule()
{
	cout << "\tEach player will draw 2 cards\n";
	cout << "\tYour score is the last digit of the sum\n";
	cout << "\tFor example, 9 and 4 makes 13 = 3. 3 and 8 makes 11 = 1)\n";
	cout << "\tA 10 or a picture (J, Q, K) counts as 0\n";
	cout << "\tIf either side's score is 8 or 9 after revealing two cards, the game is over\n";
	cout << "\tIf not, one more card may be drawn\n";
	cout << "\tThe winner is the one with score closest to 9\n\n";
}

//"J", "Q", "K" will fail, so it will return 0
int strtoint(std::string str)
{
	int num;
	std::istringstream(str) >> num;
	return num;
}

string inttostr(int n)
{
    string s;
    stringstream ss;
    ss << n;
	s = ss.str();
	return s;
}

int main()
{
	srand(time(NULL));
	int menuselection;
	int cheatmodeselection;
	int rules;
	Game g;
	cout << "Welcome to Bacarrat! Press 1 for rules. Press anything else to start playing!" << endl;
	cin >> rules;
	if (rules == 1)
	{
		printrule();
	}
	g.startGame();
}
