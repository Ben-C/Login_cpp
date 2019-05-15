#include <iostream>
#include <fstream>
#include <string>
#include "login.cpp"

bool isloggedIN()
{
	std::string userName, userPass, uN, uP;
	std::cout << "select a username: \n"; std::cin >> userName;
	std::cout << "select a password: \n"; std::cin >> userPass;
	
	std::ifstream read(".\\username.txt");
	getline(read, uN);
	getline(read, uP); 

	if (uN == userName && uP == userPass)
	{
		return true;
	}
	else
	{
		return false;
	}
}
return 0;
}