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
}

void Information::giveinfo()
{
	availableinfotoken -= 1;
}

int Information::howmanytoken()
{
	cout << "Information Tokens left: ";
	return availableinfotoken;
}