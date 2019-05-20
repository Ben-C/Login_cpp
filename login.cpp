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

int regUser(){
	bool cont;
	while(cont = true){
	std::string userName, userPass;
	std::cout << "select a username: \n"; std::cin >> userName;
	getline(std::cin, userName);
	std::cout << "select a password: \n"; std::cin >> userPass;
	getline(std::cin, userPass);
	std::ofstream file;
	file.open(".\\username.txt", std::ios::app | std::ios::out);
	file << userName << "," << userPass << std::endl;
	file.close();
	std::cout << "Would you like to Enter another user? Y/N" << std::endl;
	std::string userChoice;
	std::cin >> userChoice;
	if(userChoice == "Y"){
		cont = true;
	} 
	else{
		break;
	}
}
}

void checkLogin(){
	std::string userName, userPass;
	std::cout << "Enter your username: \n"; std::cin >> userName;
	std::cout << "Enter your password: \n"; std::cin >> userPass;
	
	std::ifstream userLog(".\\username.txt");
	if (userLog.is_open()){
		while (!userLog.eof()){
			std::string uN, uP;
			userLog >> uN >> uP;
			if (userName == uN && userPass == uP){
				std::cout << "Login Succseful!" << std::endl;
				countNumbers();
				break;
			}
			else
			{
				std::cout << "Login failed, programe will terminate!" << std::endl;
				break;
			}
		}
	}
		else 
		{
			userLog.close();
		}
}

int login() {
	int choice;
	std::cout << "1: Register\n2: Login\n"; std::cin >> choice;
	switch (choice)	{
		default:
			def();
		break;
		case 1:
			regUser();
		break;
		case 2:
			checkLogin();
		}	
	return 0;
}