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
	cout << "\tYour score is the last digit of the sum" << endl;
	cout << "\tFor example, 9 and 4 makes 13 = 3. 3 and 8 makes 11 = 1)" << endl;
	cout << "\tA 10 or a picture (J, Q, K) counts as 0" << endl;
	cout << "\tIf either side's score is 8 or 9 after revealing two cards, the game is over" << endl;	
	cout << "\tIf not, one more card may be drawn" << endl;
	cout << "\tThe winner is the one with score closest to 9" << endl;
}

bool drawthird(int player, int ai)
{
	bool match_one = (ai <= 2);											//if bank is <= 2, then draw
	bool match_two = ((ai == 3) && (player != 8));						//if bank is 3, then draw unless player drew an 8 as third card
	bool match_three = ((ai == 4) && (player >= 2) && (player <= 7));	//if bank is 4, then draw if player drew 2-7
	bool match_four = ((ai == 5) && (player >= 4) && (player <= 7));	//if bank is 5, then draw if player drew 4-7
	bool match_five = ((ai == 6) && (player >= 6) && (player <= 7));	//if bank is 6, then draw if player drew 6 or 7
																		//if bank is 7, then the banker stands 
	return (match_one || match_two || match_three || match_four || match_five);
}

void compare(int player, int ai)
{
	if (player > ai)
	{
		cout << "You win!" << endl;
		playerwin++;		
	}
	else if (player < ai)
	{
		cout << "The bank wins!" << endl;
		aiwin++;		
	}
	else if (player == ai)
	{
		cout << "It's a tie!" << endl;
	}
}
bool legalcard(string s)
{
	return ((s == "1") || (s == "2") || (s == "3") || (s == "4") || (s == "5") || 
			(s == "6") || (s == "7") || (s == "8") || (s == "9") || (s == "10") || 
			(s == "J") || (s == "Q") || (s == "K"));
}
void startgame()
{
	int repeat = 0;
do{
	srand(time(NULL));
	int card_face_value_player;
	int card_face_value_ai;
	int final_player_score;
	int final_ai_score;
	
	string p1 = randomcard();
	string a1 = randomcard();
	string p2 = randomcard();
	string a2 = randomcard();
	string p3 = "N/A";
	string a3 = "N/A";
	string thirdcardchoice = "";
    string cheat_card_selection;
    string cheat_card;

	cout << "---------------------------------------------------" << endl;
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

	card_face_value_player = strtoint(p1) + strtoint(p2);
	card_face_value_ai = strtoint(a1) + strtoint(a2);
	int decision_player = finalscore(card_face_value_player);
	int decision_ai = finalscore(card_face_value_ai);

	if ((decision_player == 8) || (decision_player == 9) || (decision_ai == 8) || (decision_ai == 9))
	{
		compare(decision_player, decision_ai);
	}
	else
	{
		cout << "Draw the 3rd card? y/n" << endl;
		cin >> thirdcardchoice;

		if (thirdcardchoice == "y")
		{
			p3 = randomcard();
			cout << "You drew: " << p3 << endl;
			if (cheat)
			{
				cout << "psst...doesn't like it? Press 999 to select your 3rd card" << endl;
				cin >> cheat_card_selection;
				if (cheat_card_selection == "999")
				{
					cout << "What would you like to draw as your 3rd card?" << endl;
					cin >> cheat_card;
					while (!legalcard(cheat_card))
					{
						cout << "Card not recognized, please choose from 1, 2, ... K" << endl;
						cin >> cheat_card;
					}
					p3 = cheat_card; 
				}
				else if (cheat_card_selection != "999")
				{
					cout << "Alright, " << p3 << " will be your 3rd card" << endl;
				}
			}
			card_face_value_player += strtoint(p3);
		}	
		//If player stayed with 2 cards, then draw if current score is 0-5 
		//If player drew the 3rd card, then react according to the drawthird() logic
		if (((thirdcardchoice == "n") && (decision_ai >= 0) && (decision_ai <= 5)) ||
			((thirdcardchoice == "y") && (drawthird(strtoint(p3), decision_ai))))
		{
			cout << "Computer has decided to draw the 3rd card!" << endl;
			a3 = randomcard();
			if (cheat)
			{
				cout << "Computer drew: " << a3 << endl;
			}
			card_face_value_ai += strtoint(a3);
		}

		final_player_score = finalscore(card_face_value_player);
		final_ai_score = finalscore(card_face_value_ai);

		cout << "player score = " << p1 << " + " << p2 << " + " << p3 << " = " << final_player_score << endl;
		cout << "ai score = " << a1 << " + " << a2 << " + " << a3 << " = " << final_ai_score << endl;
		compare(final_player_score, final_ai_score);
	}

	cout << "Score: Player: " << playerwin << " " << "Bank: " << aiwin << endl;
	cout << "Press 1 to play again" << endl;
	cin >> repeat;
}while(repeat == 1);
}

int main()
{
	int menuselection;
	int cheatmodeselection;

	cout << "Welcome to Bacarrat!" << endl;
	printrule();

	cout << "Press 999 to enter cheat mode, 0 to enter regular mode" << endl;
	cin >> cheatmodeselection;

	if (cheatmodeselection == 999)
	{
		cheat = true;
	}
	else if (cheatmodeselection != 999)
	{
		cheat = false;
	}
	srand(time(NULL));
	startgame();
}
