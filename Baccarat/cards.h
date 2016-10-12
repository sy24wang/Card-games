#ifndef __CARDS_H__
#define __CARDS_H__

#include <iostream>
#include <cstdlib>
#include <sstream>

class Card
{
	public:
	int score;
	std::string value;

	void randomCard();
	bool legalCard(std::string s);
	Card();
	
	std::string inttostr(int n)
	{
	    std::string s;
	    std::stringstream ss;
	    ss << n;
	    s = ss.str();
	    return s;
	}
	void resetCard();
};



#endif