#ifndef __FUSETOKEN_H__
#define __FUSETOKEN_H__

#include <iostream>


class Fuse
{
	int availablefusetoken;
	
	public:
	int howmanytoken();
	void wrongCardPlayed();
	Fuse(int tokens);
};	

#endif