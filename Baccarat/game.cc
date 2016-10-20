#include <iostream>
#include <string>
#include "game.h"

using namespace std;

Game::Game()
{
	cheat = true;
	Player p;
	Player ai;
	money = 0;
}

void Game::setMoney(int n)
{
	this->money = n;
}
void Game::compare(struct Player *p, struct Player *ai)
{
	cout << "---------------------------------------------------" << endl;
	cout << "player score = " << p->card1.value << " + " << p->card2.value << " + " << p->card3.value << " = " << p->score << endl;
	cout << "ai score = " << ai->card1.value << " + " << ai->card2.value << " + " << ai->card3.value << " = " << ai->score << endl;

	if (p->score > ai->score)
	{
		cout << "You win!" << endl;
		p->numOfWin++;		
	}
	else if (p->score < ai->score)
	{
		cout << "The bank wins!" << endl;
		ai->numOfWin++;
	}
	else if (p->score == ai->score)
	{
		cout << "It's a tie!" << endl;
	}
}

int Game::finalscore(int total)
{
	return total % 10;
}

//"J", "Q", "K" will fail, so it will return 0
int Game::strtoint(std::string str)
{
	int num;
	istringstream(str) >> num;
	return num;
}

bool Game::drawThird(int player, int ai)
{
	bool match_one = (ai <= 2);											//if bank is <= 2, then draw
	bool match_two = ((ai == 3) && (player != 8));						//if bank is 3, then draw unless player drew an 8 as third card
	bool match_three = ((ai == 4) && (player >= 2) && (player <= 7));	//if bank is 4, then draw if player drew 2-7
	bool match_four = ((ai == 5) && (player >= 4) && (player <= 7));	//if bank is 5, then draw if player drew 4-7
	bool match_five = ((ai == 6) && (player >= 6) && (player <= 7));	//if bank is 6, then draw if player drew 6 or 7
																		//otherwise, the banker stands 
	return (match_one || match_two || match_three || match_four || match_five);
}

bool Game::legalCard(string s)
{
	return ((s == "1") || (s == "2") || (s == "3") || (s == "4") || (s == "5") || 
			(s == "6") || (s == "7") || (s == "8") || (s == "9") || (s == "10") || 
			(s == "J") || (s == "Q") || (s == "K"));
}

void Game::startGame()
{
	/*
	cout << "Your money is: " << money << endl;
	setMoney(9000);
	cout << "Your money is: " << money << endl;	
*/

	int repeat = 0;
	int cheatmodeselection = 0;
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

do{
	srand(time(NULL));
	int card_face_value_player = 0;
	int card_face_value_ai = 0;
	int final_player_score = 0;
	int final_ai_score = 0;
	
	string thirdcardchoice = "";
	string cheat_card_selection;
	string cheat_card;
	cout << "---------------------------------------------------" << endl;
	cout << "You drew: " << p.card1.value << ", " << p.card2.value << endl;
	if (cheat)
	{
		cout << "AI drew: " << ai.card1.value << ", " << ai.card2.value << endl;
	}

	card_face_value_player = p.card1.score + p.card2.score;
	p.score = finalscore(card_face_value_player);

	card_face_value_ai = ai.card1.score + ai.card2.score;
	ai.score = finalscore(card_face_value_ai);

	//If either side's score is 8 or 9, that's the end of the game
	if ((p.score == 8) || (p.score == 9) || (ai.score == 8) || (ai.score == 9))
	{
		compare(&p, &ai);
	}

	//Otherwise, 3rd card may be drawn
	else
	{
		cout << "Draw the 3rd card? y/n" << endl;
		cin >> thirdcardchoice;

		if ((thirdcardchoice == "y") || (thirdcardchoice == "Y"))
		{
			p.card3.randomCard();
			cout << "You drew: " << p.card3.value << endl;
			
			if (cheat)
			{
				cout << "psst...doesn't like it? Press 999 to select your 3rd card" << endl;
				cin >> cheat_card_selection;
				if (cheat_card_selection == "999")
				{
					cout << "What would you like to draw as your 3rd card?" << endl;
					cin >> cheat_card;
					while (!legalCard(cheat_card))
					{
						cout << "Card not recognized, please choose from 1, 2, ... K" << endl;
						cin >> cheat_card;
					}
					p.card3.resetCard();
					p.card3.value = cheat_card;
					p.card3.score = strtoint(cheat_card);
				}
				else if (cheat_card_selection != "999")
				{
					cout << "\nAlright, " << p.card3.value << " will be your 3rd card" << endl;
				}
			}
			card_face_value_player += p.card3.score;
		}	

		//If player stayed with 2 cards, then draw if current score is 0-5 
		//If player drew the 3rd card, then react according to the drawthird() logic
		if (((thirdcardchoice == "n") && (ai.score >= 0) && (ai.score <= 5)) ||
			((thirdcardchoice == "y") && (drawThird(p.card3.score, ai.score))))
		{
			cout << "Computer has decided to draw the 3rd card!" << endl;
			ai.card3.randomCard();
			if (cheat)
			{
				cout << "Computer drew: " << ai.card3.value << endl;
			}
			card_face_value_ai += ai.card3.score;
		}
		p.score = finalscore(card_face_value_player);
		ai.score = finalscore(card_face_value_ai);
		compare(&p, &ai);
	}

	cout << "Score: Player: " << p.numOfWin << " " << "Bank: " << ai.numOfWin << endl;
	cout << "Press 1 to play again" << endl;
	cin >> repeat;
	if (repeat == 1)
	{
		p.card1.randomCard();
		p.card2.randomCard();
		p.card3.resetCard();

		ai.card1.randomCard();
		ai.card2.randomCard();
		ai.card3.resetCard();
	}
	
}while(repeat == 1);

}
