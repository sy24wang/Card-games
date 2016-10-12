#include <iostream>
#include <string>
#include "game.h"

using namespace std;



void Game::compare(struct Player p, struct Player ai)
{
	if (p.score > ai.score)
	{
		cout << "You win!" << endl;
		p.numOfWin++;		
	}
	else if (p.score < ai.score)
	{
		cout << "The bank wins!" << endl;
		ai.numOfWin++;
	}
	else if (p.score == ai.score)
	{
		cout << "It's a tie!" << endl;
	}
}

Game::Game()
{
	cout << "1\n";
	cheat = true;
	Player p;
	Player ai;
}


void Game::startGame()
{
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


	int repeat = 0;
do{
	srand(time(NULL));
	int card_face_value_player;
	int card_face_value_ai;
	int final_player_score;
	int final_ai_score;
	
	string thirdcardchoice = "";
	string cheat_card_selection;
	string cheat_card;
	p.card1.randomCard();
	p.card2.randomCard();
	ai.card1.randomCard();
	ai.card2.randomCard();
	cout << "---------------------------------------------------" << endl;
	cout << "You drew: " << p.card1.value << endl;
	if (cheat)
	{
		cout << "Computer draw: " << ai.card1.value << endl;
	}

	cout << "You drew: " << p.card2.value << endl;
	if (cheat)
	{
		cout << "Computer draw: " << ai.card2.value << endl;
	}

	card_face_value_player = strtoint(p.card1.value) + strtoint(p.card2.value);
	card_face_value_ai = strtoint(ai.card1.value) + strtoint(ai.card2.value);
	p.score = finalscore(card_face_value_player);
	ai.score = finalscore(card_face_value_ai);

	if ((p.score == 8) || (p.score == 9) || (ai.score == 8) || (ai.score == 9))
	{
		compare(p, ai);
	}/*
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
	}*/

	cout << "Score: Player: " << p.numOfWin << " " << "Bank: " << ai.numOfWin << endl;
	cout << "Press 1 to play again" << endl;
	cin >> repeat;
}while(repeat == 1);
}
