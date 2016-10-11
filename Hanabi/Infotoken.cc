#include <iostream>
#include "Infotoken.h"
using namespace std;


Information::Information(int tokens)
{
	availableinfotoken = tokens;
}

void Information::replenish()
{
	availableinfotoken += 1;
	cout << "A card has been discarded. Infotokens left: " << this->howmanytoken() << endl;
}

void Information::giveinfo()
{
	availableinfotoken -= 1;
	cout << "An information was given. Infotokens left: " << this->howmanytoken() << endl;
}

int Information::howmanytoken()
{
	return availableinfotoken;
}