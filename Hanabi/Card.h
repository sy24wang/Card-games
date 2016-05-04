#include <iostream>

class Card
{
	std::string pattern;
	int cardValue;

friend std::ostream &operator<<(std::ostream &out, const Card &s);
public:
	Card();


};

