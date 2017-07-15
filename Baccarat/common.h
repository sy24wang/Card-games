#ifndef __COMMON_H__
#define __COMMON_H__

#define DEFAULT_MONEY 1000

bool legalCard(std::string s)
{
	return ((s == "1") || (s == "2") || (s == "3") || (s == "4") || (s == "5") || 
		(s == "6") || (s == "7") || (s == "8") || (s == "9") || (s == "10") || 
		(s == "J") || (s == "Q") || (s == "K"));
}

void writeMoney(int n)
{
	std::ofstream file;
	file.open ("money.txt");
	file << n;
	file.close();
}

int loadMoney()
{
	std::string money;
	std::ifstream file("money.txt");
	if (file.is_open())
	{
		getline(file, money);
		int ret = stoi(money);
		file.close();
		int totalmoney = ret;
		if (totalmoney <= 0)
		{
			std::cout << "Uh oh, looks like you've ran out of money from last time. We'll start you off with $" << DEFAULT_MONEY << std::endl;
			return DEFAULT_MONEY;
		}
		return ret;
	}
	else
	{
		std::cout << "Looks like this is your first game. We'll start you off with $" << DEFAULT_MONEY << std::endl;
		return DEFAULT_MONEY;			//if money.txt doesn't exist yet, we'll start off with $default_money
	}
}


#endif