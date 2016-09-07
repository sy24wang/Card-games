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
bool drawthird(int player, int ai)
{
	cout << "ENTER drawthird" << endl;
	if (((player == 2) || (player == 3)) && ((ai >= 0) && (ai <= 4)))	//player's third card is 2 or 3. AI draws if current AI's score is 0-4
	{
		cout << "A" << endl;
		return true;
	}
	else if (((player == 4) || (player == 5)) && ((ai >= 0) && (ai <= 5)))	//player's third card is 4 or 5. AI draws if current AI's score is 0-5
	{
		cout << "B" << endl;
		return true;
	}
	else if (((player == 6) || (player == 7)) && ((ai >= 0) && (ai <= 6)))	//player's third card is 6 or 7. AI draws if current AI's score is 0-6
	{
		cout << "C" << endl;
		return true;
	}
	else if ((player == 8) && ((ai >= 0) && (ai <= 2)))	//player's third card is 8. AI draws if current AI's score is 0-2
	{
		cout << "D" << endl;
		return true;
	}
	else if (((player == 0) || (player == 1) || (player == 9)) && ((ai >= 0) && (ai <= 3)))	//player's third card is an ace, 9, 10, or face-card (0). AI draws if current AI's score is 0-3
	{
		cout << "E" << endl;
		return true;
	}

	return false;
}
void startgame()
{
	int repeat = 0;

	srand(time(NULL));

	do{
	
	int card_face_value_player;
	int card_face_value_ai;
	int final_player_score;
	int final_ai_score;
	
	string p1 = randomcard();
	string a1 = randomcard();
	string p2 = randomcard();
	string a2 = randomcard();
	string p3;
	string a3;
	string thirdcardchoice;
        
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

	cout << "Your cards' face value: " << card_face_value_player << endl;
	
	if (cheat)
	{
		cout << "ai's cards' face value: " << card_face_value_ai << endl;	
	}


    int aidecisionscore = finalscore(card_face_value_ai);
    int playerdecisionscore = finalscore(card_face_value_player);
    cout << "aidecisionscore = " << aidecisionscore << endl;
    cout << "playerdecisionscore = " << playerdecisionscore << endl;


	cout << "Would you like to draw the 3rd card? Type \"Yes\" or \"No\"" << endl;
	cin >> thirdcardchoice;

	if ((thirdcardchoice == "yes") || (thirdcardchoice == "Yes") || (thirdcardchoice == "y") || (thirdcardchoice == "Y"))
	{
		p3 = randomcard();
		cout << "You drew: " << p3 << endl;
		card_face_value_player += strtoint(p3);
	}	
	cout << "===================\n";
	cout << "card_face_value_player = " << card_face_value_player << endl;
	cout << "card_face_value_ai = " << card_face_value_ai << endl;


	if (drawthird(playerdecisionscore, card_face_value_ai))
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

        cout << "player score = " << final_player_score << endl;

	cout << "ai score = " << final_ai_score << endl;
	

	if(final_player_score == final_ai_score)
	{
		cout << "It's a tie!" << endl;
	}
	else if (final_player_score > final_ai_score)
	{
		cout << "You win!" << endl;
		playerwin++;
	}
	else if (final_player_score < final_ai_score)
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
	int cheatmodeselection;

	cout << "Welcome to Bacarrat! Press 1 for rule, press 2 to start playing" << endl;
	cin >> menuselection;

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
