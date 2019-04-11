#include <iostream>
#include <fstream>
#include <string>
//#include "isloggedIN.cpp"
#include "countNumbers.cpp"

int login() {
	int choice;
    bool isloggedIN();
	std::cout << "1: Register\n2: Login\n"; std::cin >> choice;
	if (choice == 1)
	{
		std::string userName, userPass;

		std::cout << "select a username: \n"; std::cin >> userName;
		std::cout << "select a password: \n"; std::cin >> userPass;
		
		std::ofstream file;
		file.open(".\\username.txt");

		file << userName << std::endl << userPass;
		file.close();
		return login();
	}
	else if (choice ==2)
	{

		bool status = isloggedIN();
		if (!status)
		{
			return 0;		}
		else
		{
			return countNumbers();
		}
		
	}
	
	return 0;
}