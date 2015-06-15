#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>

using namespace std;

bool cheat = true;
int playerwin = 0;
int aiwin = 0;

string inttostr(int n)
{
    string s;
    stringstream ss;
    ss << n;
    s = ss.str();
    return s;
}

//"J", "Q", "K" will fail, so it will return 0
int strtoint(string str)
{
    int num;
    istringstream(str) >> num;

    return num;
}

string randomcard()
{		
	//generate number between 1 and 13
	int cardvalue = rand() % 13 + 1;

	if (cardvalue == 11)
	{
		return "J";
	}
	else if (cardvalue == 12)
	{
		return "Q";
	}
	else if (cardvalue == 13)
	{
		return "K";
	}
	else return inttostr(cardvalue);
}

int finalscore(int total)
{
	return total % 10;
}

void printrule()
{
	cout << "Rule:" << endl;
	cout << "\tEach player will draw 2 cards" << endl;
	cout << "\tThe value is the 2 cards' face value added up" << endl;
	cout << "\tYou may choose to draw the 3rd card, after knowing the first 2 cards" << endl;
	cout << "\tYour score is the last digit of the value. (ex. 13 = 3, 17 = 7, 11 = 1)" << endl;
        cout << "\tA 10 or a picture (J, Q, K) counts as 0 value" << endl;
	cout << "\tThe winner is the one with score closest to 9" << endl;
}
	
void startgame()
{
	int repeat = 0;

	srand(time(NULL));

	do{
	
	int playervalue;
	int aivalue;
	int playerscore;
	int aiscore;
	
	string p1 = randomcard();
	string a1 = randomcard();
	string p2 = randomcard();
	string a2 = randomcard();
	string p3;
	string a3;
	string thirdcardchoice;
        

	cout << "You drew: " << p1 << endl;
	if (cheat)
        {
		cout << "Computer draw: " << a1 << endl;
        }

	cout << "You drew: " << p2 << endl;
	if (cheat)
	{
		cout << "Computer draw: " << a2 << endl;
	}

	playervalue = strtoint(p1) + strtoint(p2);
	aivalue = strtoint(a1) + strtoint(a2);

	cout << "Your cards' face value: " << playervalue << endl;
	
	if (cheat)
	{
		cout << "ai's cards' face value: " << aivalue << endl;	
	}

        int aidecisionscore = finalscore(aivalue);
        int playerdecisionscore = finalscore(playervalue);

        if (aidecisionscore <= playerdecisionscore)
        {
		cout << "Computer has decided to draw the 3rd card!" << endl;
                a3 = randomcard();
		if (cheat)
		{
                	cout << "Computer drew: " << a3 << endl;
                }
		aivalue += strtoint(a3);
        }

	cout << "Would you like to draw the 3rd card? Type \"Yes\" or \"No\"" << endl;
	cin >> thirdcardchoice;

				
	if ((thirdcardchoice == "yes") || (thirdcardchoice == "Yes") || (thirdcardchoice == "y") || (thirdcardchoice == "Y"))
	{
		p3 = randomcard();
		cout << "You drew: " << p3 << endl;
		playervalue += strtoint(p3);
	}	


	playerscore = finalscore(playervalue);
        aiscore = finalscore(aivalue);

        cout << "player score = " << playerscore << endl;

        if (cheat)
	{
		cout << "ai score = " << aiscore << endl;
	}

	if(playerscore == aiscore)
	{
		cout << "It's a tie!" << endl;
	}
	else if (playerscore > aiscore)
	{
		cout << "You win!" << endl;
		playerwin++;
	}
	else if (playerscore < aiscore)
	{
		cout << "Computer wins this time" << endl;
		aiwin++;
	}

	cout << "Score: Player: " << playerwin << " " << "Computer: " << aiwin << endl;
	cout << "play again? Press 1 for yes, 2 for no" << endl;
	cin >> repeat;

}while(repeat == 1);

}

int main()
{
	int menuselection;
	cout << strtoint("J") << endl;
	cout << strtoint("Q") << endl;
	cout << strtoint("K") << endl;

	cout << "Welcome to Bacarrat! Press 1 for rule, press 2 to start playing" << endl;
	cin >> menuselection;

	if (menuselection == 1)
	{
		printrule();
		srand(time(NULL));
		startgame();
	}
	else if (menuselection == 2)	
	{
		srand(time(NULL));
		startgame();
	}
	else
	{
		cout << "not recognized, exiting..." << endl;
		return 0;
	}
	
}
