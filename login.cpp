#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "countNumbers.cpp"
#include "isloggedIN.cpp"

int def(){
	std::cout << '\a';
	std::cout << "Choice not recognised programme will now terminate.";
	return 0;
}

int checkLogin(){
	std::string userName, userPass;
	std::ofstream file;
	std::cout << "select a username: \n"; std::cin >> userName;
	std::cout << "select a password: \n"; std::cin >> userPass;
	file.open(".\\username.txt");
	file << userName << std::endl << userPass;
	file.close();
	return 0;
}
int loginFailed(){
	bool status = isloggedIN();
		if (!status)
		{
			std::cout << '\a';
			std::cout << "Login failed, programme will now terminate!" << std::endl;
			getch();
			return 0;	
		}
		else
		{
			return countNumbers();
		}
}

int login() {
	int choice;
	bool isloggedIN();
	std::cout << "1: Register\n2: Login\n"; std::cin >> choice;
	switch (choice)	{
		default:
			def();
		break;
		case 1:
			checkLogin();
		break;
		case 2:
			loginFailed();
		}	
	return 0;
}