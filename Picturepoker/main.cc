#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;


string junk = "junk";
string onepair = "1 pair";
string twopair = "2 pair";
string threeofakind = "3 of a kind";
string fullhouse = "full house";
string fourofakind = "4 of a kind";
string fiveofakind = "5 of a kind";


string debugoutcome = fiveofakind;


/*

returning value:

bet * 16 if 5 of a kind
bet * 8 if 4 of a kind
bet * 6 if full house
bet * 4 if 3 of a kind
bet * 3 if 2 pairs
bet * 2 if 1 pairs

0 if tie
-1 if lost

*/

int compare(string playerhand, string aihand, int bet)
{
	
	if (playerhand == fiveofakind)
	{
		if (aihand == fiveofakind)
		{
			return 0;
		}
		else
		{
			return bet * 16;
		}
	}

	if (playerhand == fourofakind)
	{
		if (aihand == fiveofakind)
		{
			return -1;
		}
		if (aihand == fourofakind)
		{
			return 0;
		}
		else
		{
			return bet * 8;
		}
	}

	if (playerhand == fullhouse)
	{
		if ((aihand == fiveofakind) || (aihand == fourofakind))
		{
			return -1;
		}
		if (aihand == fullhouse)
		{
			return 0;
		}
		else
		{
			return bet * 6;
		}
	}
	
	if (playerhand == threeofakind)
	{
		if ((aihand == fiveofakind) || (aihand == fourofakind) || (aihand == fullhouse))
		{
			return -1;
		}
		if (aihand == threeofakind)
		{
			return 0;
		}
		else
		{
			return bet * 4;
		}
	}

	if (playerhand == twopair)
	{
		if (aihand == twopair)
		{
			return 0;
		}
		if ((aihand == onepair) || (aihand == junk))
		{
			return bet * 3;
		}
		else
		{
			return -1;
		}
	}

	if (playerhand == onepair)
	{
		if (aihand == onepair)
		{
			return 0;
		}
		if (aihand == junk)
		{
			return bet * 2;
		}
		else
		{
			return -1;
		}
	}
	if (playerhand == junk)
	{
		if (aihand == junk)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}

}



void startgame(string name, int money)
{
	string ingamecommand;
	int betamount = 0;

		cout << "Enter q or quit to exit and save your game at anytime\n";
		cout << "name = " << name << ", money = " << money << endl;

		while(cin >> ingamecommand)
		{
			if (money == 0)
			{
				cout << "Out of money! Starting a new game...\n";
				startgame(name, 10);
			}

			transform (ingamecommand.begin(), ingamecommand.end(), ingamecommand.begin(), ::tolower);
			
			if ((ingamecommand == "b") || (ingamecommand == "bet"))
			{
				if ((betamount - 1) < 0)
				{
					cout << "Sorry, you don't have enough money\n";
					cout << "bet did not change: " << betamount << endl;
					continue;	
				}
				else
				{
					betamount++;
					money--;
					cout << "currently betting: " << betamount << endl;
				}
			}
			if ((ingamecommand == "c") || (ingamecommand == "compare"))
			{
				int reward = compare(debugoutcome, "junk", betamount);
				
				if (reward == 0)
				{
					cout << "Hmm... you tied\n";
				}
				else if (reward == -1)
				{
					cout << "Sorry, you lost\n";
				}

				else
				{
					cout << "You win! reward: " << reward << endl;
					money += reward;
					cout << "You now have $" << money << endl;
				}
				betamount = 0;
				continue;
			}

			if ((ingamecommand == "q") || (ingamecommand == "quit"))
			{
				cin.ignore();		//to ignore the "q" we just cin'ed in
				ofstream file;
				file.open ("game.sav");
				cerr << "name: " << name << ", $" << money << endl;
				file << name << endl << money;
				file.close();
				return;
			}
		}

}

int main()
{
	string selection;
	string ingamecommand;
	string name;
	int money;


	cout << "Welcome to picture poker!" << endl;
	cout << "What would like to do?" << endl;
	cout << "Type \"new\" to start a new game (WARNING: will override any previous saved game!)" << endl;
	cout << "Type \"load\" to load your previously saved game" << endl;

	cin >> selection;
	transform (selection.begin(), selection.end(), selection.begin(), ::tolower);

	if (selection == "new")
	{
		cin.ignore();
		cout << "Name:";
		getline(cin, name);
		cout << "Welcome, " << name << endl;
		startgame(name, 10);
	}
	else if (selection == "load")
	{
		string line;
		ifstream file("game.sav");

		if (file.is_open())
		{
			cout << "file's open" << endl;
			getline(file, name);
			file >> money;
			
			file.close();
			startgame(name, money);
		}

		else
		{
			cin.ignore();
			cout << "Sorry, you have no saved game\n";
			cout << "Name:";
			getline(cin, name);
			startgame(name, 10);
		}
	}
	else
	{
		cout << "Invalid command, exiting..." << endl;
	}

}