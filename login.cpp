#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "countNumbers.cpp"
int login() {
	int choice;
	std::string userName, userPass;
	std::ofstream file;
    bool isloggedIN();
	std::cout << "1: Register\n2: Login\n"; std::cin >> choice;
	switch (choice)	{
		case 1:
			std::cout << "select a username: \n"; std::cin >> userName;
			std::cout << "select a password: \n"; std::cin >> userPass;
			file.open(".\\username.txt");
			file << userName << std::endl << userPass;
			file.close();
			return login();
		break;
		case 2:
		bool status = isloggedIN();
		if (!status)
		{
			std::cout << '\a';
			std::cout << "Login failed, please try again!" << std::endl;
			getch();
			return 0;	
		}
		else
		{
			return countNumbers();
		}
	}	
	return 0;
}