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
}

int Fuse::howmanytoken()
{
	cout << "Fuse Tokens left: ";
	return availablefusetoken;
}