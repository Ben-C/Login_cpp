#include <iostream>
#include <fstream>
#include <string>

bool isloggedIN()
{
	std::string userName, userPass;
	std::cout << "select a username: \n"; std::cin >> userName;
	std::cout << "select a password: \n"; std::cin >> userPass;
	
	std::ifstream read(".\\username.txt");
	while (!read.eof())
	{
		std::string uN, uP;
		read >> uN >> uP;
		if (uN == userName && uP == userPass)
	{
		return true;
	}
	else
	{
		return false;
	}

	}
return 0;}