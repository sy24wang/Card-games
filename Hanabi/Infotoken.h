#ifndef __INFOTOKEN_H__
#define __INFOTOKEN_H__

#include <iostream>


class Information
{
	int availableinfotoken;
	
	public:
	int howmanytoken();
	void replenish();
	void giveinfo();
	Information(int tokens);
};	

#endif