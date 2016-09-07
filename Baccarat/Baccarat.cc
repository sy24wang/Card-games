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
	bool match_one = (((player == 2) || (player == 3)) && ((ai >= 0) && (ai <= 4)));	//player's third card is 2 or 3. AI draws if current AI's score is 0-4
	bool match_two = (((player == 4) || (player == 5)) && ((ai >= 0) && (ai <= 5)));	//player's third card is 4 or 5. AI draws if current AI's score is 0-5
	bool match_three = (((player == 6) || (player == 7)) && ((ai >= 0) && (ai <= 6)));	//player's third card is 6 or 7. AI draws if current AI's score is 0-6
	bool match_four = (((player == 0) || (player == 1) || (player == 9)) && ((ai >= 0) && (ai <= 3)));	//player's third card is an ace, 9, 10, or face-card (0). AI draws if current AI's score is 0-3
	bool match_five = ((player == 8) && ((ai >= 0) && (ai <= 2))); //player's third card is 8. AI draws if current AI's score is 0-2
	return (match_one || match_two || match_three || match_four || match_five);
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
	string p3 = "N/A";
	string a3 = "N/A";
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
	int decision_ai = finalscore(card_face_value_ai);

	cout << "Press y to draw the 3rd card" << endl;
	cin >> thirdcardchoice;

	if ((thirdcardchoice == "y") || (thirdcardchoice == "Y"))
	{
		p3 = randomcard();
		cout << "You drew: " << p3 << endl;
		card_face_value_player += strtoint(p3);

		//note: we want to compare ai's hand (2 cards) vs. the 3rd card (that player just drew)
		if (drawthird(strtoint(p3), decision_ai))
		{
			cout << "Computer has decided to draw the 3rd card!" << endl;
	        a3 = randomcard();
			if (cheat)
			{
	        	cout << "Computer drew: " << a3 << endl;
	        }
			card_face_value_ai += strtoint(a3);
		}
	}	
	/*
	else	//if player did not choose to draw the 3rd card: AI will draw if it's at a strict disadvantage
			//TO DO: perhaps it can be improved further (assuming cheat mode is off, player doesn't know that AI's at a disadvantage)
	{
		if (decision_ai < decision_player)
		{
			cout << "Computer has decided to draw the 3rd card!" << endl;
	        a3 = randomcard();
			if (cheat)
			{
	        	cout << "Computer drew: " << a3 << endl;
	        }
			card_face_value_ai += strtoint(a3);			
		}
	}*/

	final_player_score = finalscore(card_face_value_player);
    final_ai_score = finalscore(card_face_value_ai);

    cout << "player score = " << p1 << " + " << p2 << " + " << p3 << " = " << final_player_score << endl;
    cout << "ai score = " << a1 << " + " << a2 << " + " << a3 << " = " << final_ai_score << endl;

	if(final_player_score == final_ai_score)
	{
		cout << "It's a tie!" << endl;
	}
	else if (final_player_score > final_ai_score)
	{
		cout << "You win!" << endl;
		playerwin++;
	}
	else 
	{
		cout << "The bank wins!" << endl;
		aiwin++;
	}

	cout << "Score: Player: " << playerwin << " " << "Bank: " << aiwin << endl;
	cout << "Press 1 to play again" << endl;
	cin >> repeat;

	} while(repeat == 1);

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
