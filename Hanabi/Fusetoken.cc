#include <iostream>
#include "Fusetoken.h"
using namespace std;

Fuse::Fuse(int tokens)
{
	availablefusetoken = tokens;
}

void Fuse::wrongCardPlayed()
{
	availablefusetoken -= 1;
	cout << "ALERT! Wrong card played! Fusetokens left: " << this->howmanytoken() << endl;
}

int Fuse::howmanytoken()
{
	return availablefusetoken;
}