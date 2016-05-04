#include <iostream>
#include <Infotoken.h>
using namespace std;


Information::Information(int tokens)
{
	this->availableinfotoken = tokens;
}

void Information::replenish()
{
	this->availableinfotoken += 1;
}
