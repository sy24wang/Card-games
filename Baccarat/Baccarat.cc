#include <iostream>
#include <fstream>
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

int strtoint(std::string str)
{
	int num;
	std::istringstream(str) >> num;
	return num;
}

void writeMoney(int n)
{
	ofstream file;
	file.open ("money.txt");
	file << n;
	file.close();
}

int loadMoney()
{
	string money;
	ifstream file("money.txt");
	if (file.is_open())
	{
		getline(file, money);
		int ret = strtoint(money);
		file.close();
		return ret;
	}
		
	else
	{
		cout << "ERROR: unable to open file";
		return 0;
	}
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

	g.updateMoney(1000);
	writeMoney(1000);
	int moneyAvailable;
	moneyAvailable = loadMoney();
	cout << moneyAvailable << endl;
	g.startGame();
}
